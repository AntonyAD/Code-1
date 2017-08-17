#pragma once
#include<iostream>
using namespace std;

//auto_ptr�汾������ָ����õ��ǹ���Ȩת�Ƶķ�����
//����a�����b����֮��a������ΪNULL����֮����
//�ٷ���a����ֻ��bһ������ά���ÿռ䡣

//ȱ�㣺��������ʵ�ֿ�������͸�ֵ��������ص�Ŀ��
template <class T>
class Auto_ptr
{
public:
	Auto_ptr()
		:_ptr(NULL)
	{}

	Auto_ptr(T* ptr)
		:_ptr(ptr)
	{}
	//��������--����Ȩת��
	Auto_ptr(Auto_ptr<T>& ap)
	{
		_ptr = ap._ptr;
		ap._ptr = NULL;//ʧЧ
	}
	//��ֵ���������--����Ȩת��
	Auto_ptr<T>& operator=(Auto_ptr<T>& ap)
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

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~Auto_ptr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
protected:
	T* _ptr;
};

struct TT
{
	int a = 1;
	char c = 'x';
};
///////////////////////////////////////////////////
//////////////////////////////////////////////////
//����������
// ����һ: ��Դת�ƺ�ap1,ap2�ٲ��ܷ��ʿռ���
//�������const���͵�ָ�룬�ٲ��������������ָ����
//��������������ָ��������ʵ�δ���ʱ���������ָ���ں������ٲ��ܷ���
void Test()
{
	int* p = new int;
	Auto_ptr<int> ap(p);
	Auto_ptr<int> ap1(ap);
	Auto_ptr<int> ap2(new int);
	ap2 = ap1;
	//*ap = 10;//ʧЧ���޷�����
	//*ap1 = 20;
	//const Auto_ptr<int> app(p);
	//Auto_ptr<int> app1(app);


	/*Auto_ptr<TT> ap2 = new TT;
	ap2->a = 22;
	cout << ap2->a << endl;
	cout << ap2->c << endl;*/

}