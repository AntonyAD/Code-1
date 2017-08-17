#pragma once
#include<iostream>
using namespace std;

//auto_ptr�汾������ָ����õ��ǹ���Ȩת�Ƶķ�����
//����a�����b����֮��a������ΪNULL����֮����
//�ٷ���a����ֻ��bһ������ά���ÿռ䡣

//ȱ�㣺��������ʵ�ֿ�������͸�ֵ��������ص�Ŀ��
template <class T>
class Auto_ptr_second
{
public:
	Auto_ptr_second()
		:_ptr(NULL)
		, _owner(false)
	{}

	Auto_ptr_second(T* ptr)
		:_ptr(ptr)
		, _owner(false)
	{
		if (NULL != ptr)
			_owner = true;
	}
	//��������--����Ȩת��
	Auto_ptr_second(const Auto_ptr_second<T>& ap)
		:_ptr(ap._ptr)
		, _owner(ap._owner)
	{
		ap._owner = false;
	}
	//��ֵ���������--����Ȩת��
	Auto_ptr_second<T>& operator=(const Auto_ptr_second<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr && _owner)
			{
				delete _ptr;
				_ptr = ap._ptr;
			}
			_owner = true;
			ap._owner = false;
		}
		return *this;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~Auto_ptr_second()
	{
		if (_ptr)
		{
			if (_owner == true)
			{
				delete _ptr;
				_ptr = NULL;
				_owner = false;
			}
		}
	}
protected:
	T* _ptr;
	mutable bool _owner;
};
//mutable�ؼ��֣��ɱ�ģ���ʹ��const���ε������mutable���ε����ԱҲ�ǿ��Ըı��


//��Ȼ���������һ������������ǲ������µ����⣬ap1,ap2,ap4��Ϊ��Ұָ�룬ֻ�ͷ���ap5
void Test1()
{
	int* p = new int;
	Auto_ptr_second<int> ap(p);
	Auto_ptr_second<int> ap1(ap);
	Auto_ptr_second<int> ap2(new int);
	ap2 = ap1;
	*ap = 10;
	*ap1 = 20;

	const Auto_ptr_second<int> app(new int);
	Auto_ptr_second<int> app1(app);


}