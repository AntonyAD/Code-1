#pragma once
#include<iostream>
using namespace std;

template <class T>
class Auto_ptrref
{
public:
	Auto_ptrref(T* ptr = NULL)
		:_ptr(ptr)
	{}
	T* _ptr;
};

template <class T>
class Auto_ptr_third
{
public:
	Auto_ptr_third()
		:_ptr(NULL)
	{}

	Auto_ptr_third(T* ptr)
		:_ptr(ptr)
	{}
	//��������--����Ȩת��
	Auto_ptr_third(Auto_ptr_third<T>& ap)
	{
		_ptr = ap._ptr;
		ap._ptr = NULL;//ʧЧ
	}
	//��ֵ���������--����Ȩת��
	Auto_ptr_third<T>& operator=(Auto_ptr_third<T>& ap)
	{
		if (this != &ap)
		{
			if (NULL != _ptr)
				delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		return *this;
	}

	//����autoptrref()
	operator Auto_ptrref<T>()//��Auto_ptr<T>ת��ΪAuto_ptrref<T>
	{
		Auto_ptrref<T> temp(_ptr);
		_ptr = NULL;
		return temp;
	}

	//������һ���������캯��
	Auto_ptr_third(const Auto_ptrref<T>& apr)
		:_ptr(apr._ptr)
	{}


	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~Auto_ptr_third()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
protected:
	T* _ptr;
};


void Test3()
{
	Auto_ptr_third<int> ap(Auto_ptrref<int>(Auto_ptr_third<int>(new int)));
}