#pragma once

#include<malloc.h>
#include<stdlib.h>
#include<iostream>

/*
*
*1.��̬���ݳ�Ա�ĳ�ʼֵ
*2.volatile
*/

//http://blog.csdn.net/boydfd/article/details/44900331
//�ռ�������
//һ���ռ�������





template <int inst>
class Mallocalloctemplate
{
private:
	//�ڴ�����ʧ�ܵ���
	static void* _oom_malloc(size_t);
	static void* _oom_realloc(void*, size_t);
	static void(*_Malloc_alloc_oom_handler)();
public:
	static void* Allocate(size_t s)
	{
		void* result = malloc(s);
		if (0 == result)
			result = _oom_malloc(s);
		return result;
	}

	static void Deallocate(void* p, size_t)//size_t??
	{
		free(p);
	}

	static void* Reallocate(void*_p, size_t, size_t new_size)
	{
		void* result = realloc(_p, new_size);
		if (0 == result)
			result = _oom_realloc(_p, new_size);
		return result;
	}
	//?????
	static void(*_set_malloc_handler(void(*f)()))()
	{
		void(*old)() = Mallocalloc_oomhandler;
		Mallocalloc_oomhandler = f;
		return (old);
	}

};

template <int inst>
void(*Mallocalloctemplate<inst>::_Malloc_alloc_oom_handler)() = 0;

template <int inst>
void* Mallocalloctemplate<inst>::_oom_malloc(size_t s)
{
	void(*_my_malloc_handler)();
	void* _result;
	//for(;;)��while(1)������
	for (;;)
	{
		_my_malloc_handler = _Malloc_alloc_oom_handler;
		if (_my_malloc_handler == 0)
		{
			//�׳��쳣
			exit(1);
		}
		(*_my_malloc_handler)();
		_result = malloc(s);
		if (_result)
			return _result;
	}
}

template <int inst>
void* Mallocalloctemplate<inst>::_oom_realloc(void* _p, size_t s)
{
	void(*_my_malloc_handler)();
	void* _result;
	//for(;;)��while(1)������
	for (;;)
	{
		_my_malloc_handler = _Malloc_alloc_oom_handler;
		if (_my_malloc_handler == 0)
		{
			//�׳��쳣
			exit(1);
		}
		(*_my_malloc_handler)();
		_result = realloc(_p, s);
		if (_result)
			return _result;
	}
}

typedef Mallocalloctemplate<0> malloc_alloc;
//�����ռ�������

template <int inst>
class Defaultalloctemplate
{
private:
	enum{ _ALIGN = 8 };
	enum{ _MAX_BYTES = 128 };
	enum{ _NFREELISTS = 16 };
	//free_list���
	union _obj
	{
		union _obj* _freelist_link;
		char client_data[1];//Ϊʲô��1
	};

	static _obj* volatile free_list[_NFREELISTS];//free_list
	//��ȡfree_list���±�
	static size_t free_list_index(size_t n)
	{
		return (((n)+_ALIGN - 1) / (_ALIGN));
	}
	//������СΪ8�ı���
	static size_t _round_up(size_t bytes)
	{
		return ((bytes + _ALIGN - 1) & ~(_ALIGN - 1));
	}

	static void* refill(size_t bytes)
	{
		/*���ڴ����Ϊ�������С���ڴ�
		* ��ʱbytes�Ѿ��Ǳ��������(��8�ı���)
		*
		*�趨ÿ�������С���ڴ����(�ٵ�20)�����ܵĿռ䳤��Ϊ20*bytes
		*���ú���_chunk_alloc���ڴ���л�ȡ
		*�������һ��С���ڴ棬�ȸ�������
		*����һ�飬������ӦС���ڴ������
		*/
		int n = 20;
		_obj* volatile* my_free_list;//?????????????
		_obj* result;
		_obj* current;
		_obj* next;
		int i = 1;
		char* chunk = _chunk_alloc(bytes, n);

		if (1 == n)
			return chunk;
		my_free_list = free_list + free_list_index(bytes);
		result = (_obj*)chunk;
		*my_free_list = next = (_obj*)(chunk + bytes);
		for (i = 1;; ++i)
		{
			current = next;
			next = (_obj*)((char*)next + bytes);
			if (n - 1 == i)
			{
				current->_freelist_link = 0;
				break;
			}
			else
			{
				current->_freelist_link = next;
			}
		}
		return result;
	}
	static char* _chunk_alloc(size_t bytes, int& n)
	{
		char* result;
		size_t totalsize = n*bytes;
		size_t poolsize = end_free - start_free;

		if (poolsize >= totalsize)
		{
			//�ڴ�������㹻
			result = start_free;
			start_free += totalsize;
			return result;
		}
		else if (poolsize >= bytes)
		{
			//�ڴ����������20�����Ǵ��ڵ���һ��С���ڴ�
			n = poolsize / bytes;
			totalsize = n*bytes;
			result = start_free;
			start_free += totalsize;
			return result;
		}
		else
		{
			//�ڴ����������һ��С���ڴ�
			if (poolsize > 0)
			{
				//�ڴ��������Ϊ0����ʣ���ڴ������ʺϴ�С������
				_obj* volatile* my_free_list;
				my_free_list = free_list + free_list_index(poolsize);
				((_obj*)start_free)->_freelist_link = *my_free_list;
				*my_free_list = (_obj*)start_free;
			}

			//�ڴ��Ϊ��
			//�Ӷ��Ͽ���
			//mallocʧ�ܣ�heap�Ͽռ䲻�㣬�鿴��û�п��е�����
			//û�о͵���һ���ռ�������
			size_t get_heap_size = 2 * totalsize + _round_up(heap_size >> 4);

			start_free = (char*)malloc(get_heap_size);
			if (0 == start_free)
			{
				//heap������ʧ��
				int i;
				_obj* volatile* my_free_list, *p;

				for (i = bytes; i <= _MAX_BYTES; i += _ALIGN)
				{
					my_free_list = free_list + free_list_index(i);
					p = *my_free_list;
					if (0 != p)
					{
						*my_free_list = p->_freelist_link;
						start_free = (char*)p;
						end_free = start_free + i;
						return (_chunk_alloc(bytes, n));
					}
				}
				//����һ���ռ�������
				end_free = 0;
				start_free = (char*)malloc_alloc::Allocate(bytes);
			}
			heap_size += get_heap_size;
			end_free = start_free + get_heap_size;
			return (_chunk_alloc(bytes, n));
		}
	}
public:
	static void* Allocate(size_t n)
	{
		/*
		*����128����һ������������
		*С��128:
		*��free_list���ң��оͷ���,��������
		*û�оʹ��ڴ����Ϊfree_list����==>refill
		*/
		void* ret = NULL;
		_obj* volatile* my_free_list;

		if (n > (size_t)_MAX_BYTES)
		{
			ret = malloc_alloc::Allocate(n);
		}
		else
		{
			my_free_list = free_list + free_list_index(n);
			_obj*result = *my_free_list;
			if (result == 0)
			{
				//free_list��û��
				return refill(_round_up(n));//??
			}
			//free_list����
			*my_free_list = result->_freelist_link;
			ret = result;
		}
		return ret;
	}

	static void Deallocate(void* p, size_t n)
	{
		/*
		*�������128������һ���ռ���������Deallocate
		*С��128����������Ӧ����
		*/
		_obj* volatile* my_free_list;
		_obj* q = (_obj*)p;
		if (n > _MAX_BYTES)
		{
			malloc_alloc::Deallocate(p, n);
			return;
		}
		my_free_list = free_list + free_list_index(n);
		q->_freelist_link = *my_free_list;
		*my_free_list = q;
	}
	static void Reallocate(void* p, size_t old_size, size_t new_size)
	{
		/*���·����ڴ�
		*�¾ɿռ䶼����128������realloc����
		*С��128:
		*�¾ɿռ���ȣ����ؾɿռ�
		*����ȣ����ö����ռ�������Allocate,���ɿռ俽�����¿ռ䣬�ͷžɿռ�
		*
		*/
		void* result;
		size_t copy_size;
		if (old_size > _MAX_BYTES && new_size > _MAX_BYTES)
		{
			return realloc(p, new_size);
		}

		if (_round_up(old_size) == _round_up(new_size))
		{
			return p;
		}
		result = Allocate(new_size);
		copy_size = new_size > old_szie ? new_size : old_size;
		memcpy(result, p, copy_size);
		Deallocate(p, old_size);
		return result;
	}

private:
	static char* start_free;//�ڴ�ؿ�ʼλ��
	static char* end_free;//�ڴ�ؽ���λ��
	static size_t heap_size;//�Ѿ�����Ķѿռ�

};
template <int inst>
char* Defaultalloctemplate<inst>::start_free = 0;

template <int inst>
char* Defaultalloctemplate<inst>::end_free = 0;

template <int inst>
size_t Defaultalloctemplate<inst>::heap_size = 0;

template <int inst>
typename Defaultalloctemplate<inst>::_obj* \
volatile Defaultalloctemplate<inst>::free_list[_NFREELISTS] = \
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

//typedef Defaultalloctemplate<0> alloc;

#ifdef USE_MALLOC
typedef malloc_alloc alloc;
#else
typedef Defaultalloctemplate<0> alloc;
#endif



template <class T, class Alloc = alloc>
class simple_alloc
{
public:
	static T* Allocate(size_t n)
	{
		return 0 == n ? 0 : (T*)Alloc::Allocate(n*sizeof(T));
	}

	static T* Allocate()
	{
		return (T*)Alloc::Allocate(sizeof(T));
	}

	static void Deallocate(T* _p, size_t n)
	{
		if (0 != n)
			Alloc::Deallocate(_p, n*sizeof(T));
	}

	static void Deallocate(T* _p)
	{
		Alloc::Deallocate(_p, sizeof(T));
	}
};