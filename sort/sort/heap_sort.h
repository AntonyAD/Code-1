#pragma once

#include<vector>


//�Ƚ���---�º���
template <class T>
struct Less
{
	bool operator()(T& left, T& right)
	{
		return left < right;
	}
};
template <class T>
struct Greater
{
	bool operator()(T& left, T& right)
	{
		return left > right;
	}
};


template <class T,class Compare = Less<T>>
class Heap
{
public:
	Heap()
	{}
	Heap(const T arr[], size_t size)
	{
		_v.resize(size);//����ռ�
		for (size_t i = 0; i < size; ++i)
		{
			_v[i] = arr[i];
		}
		//�ҵ�������һ����Ҷ�ӽ��---vector���һ��Ԫ�ص�˫��
		int root = (_v.size() - 2) >> 1;
		for (; root >= 0; --root)
		{
			Adjust(root);
		}
	}

	void Push_heap(const T& value)
	{
		_v.push_back(value);
		if (_v.size() == 1)
			return;
		int root = _v.size()-1;
		Adjust(root);
	}

	size_t Size()
	{
		return _v.size();
	}

	bool Empty()
	{
		return _v.empty();
	}

	T& Top()
	{
		return _v[0];
	}

	void pop_heap()
	{
		if (_v.empty())
		{
			std::swap(_v[0],_v[_v.size()-1]);
			_v.pop_back();
			Adjust(0);
		}
	}
private:
	void Adjust(size_t root)
	{
		Compare com;
		size_t parent = root;
		size_t child = 2 * root + 1;//����
		while (child<_v.size())
		{
			if (child + 1 < _v.size() && com(_v[child + 1],_v[child])/* _v[child + 1] < _v[child]*/)//���Һ�����С��һ��
				child += 1;
			if (com(_v[child] , _v[parent]))//�жϺ��Ӹ�˫�׵Ĵ�С
			{
				std::swap(_v[child], _v[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				return;
			}
		}
	}

private:
	vector<T> _v;
};


void Test_heap()
{
	int arr[] = {68,50,65,21,31,32,26,19,16,13,24};
	Heap<int,Greater<int>> h(arr,sizeof(arr)/sizeof(arr[0]));

}
