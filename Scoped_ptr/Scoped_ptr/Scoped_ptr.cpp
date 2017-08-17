#pragma once

using namespace std;


//scoped_ptr ������
//���ÿ������캯���͸�ֵ���������

template <class T>
class Scoped_ptr
{
public:
	Scoped_ptr(T* ptr = NULL)
		:_ptr(ptr)
	{}

	~Scoped_ptr()
	{
		if (_ptr)
			delete _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	Scoped_ptr(const Scoped_ptr<T>& sp);
	Scoped_ptr<T>& operator=(const Scoped_ptr<T>& sp);
protected:
	T* _ptr;
};

int main()
{
	Scoped_ptr<int> ap(new int);
	Scoped_ptr<int> ap1(new int);
	//ap = ap1;
	//Scoped_ptr<int> ap2(ap);
	return 0;
}

/*
//����һ�����������캯���͸�ֵ��������غ�������˽�г�Ա�����������������壬���������ΪNULL����Ϊû���κ�����
private:
//��������
scopedptr(const scopedptr<int>& sp)
{}
scopedptr<T> operator=(const scopedptr<T>& ap)//ȱ�㣺�������θ���ʵ��
{}

//�����������������캯���͸�ֵ��������غ������ɹ��������Ա������������������
scopedptr(const scopedptr<int>& sp);
scopedptr<T> operator=(const scopedptr<T>& ap);//ȱ�㣺����������ܻ����û�����������Լ�����

//�����������������캯���͸�ֵ��������غ�������˽�еĳ�Ա��������ֻ����������
private:
scopedptr(const scopedptr<int>& sp);
scopedptr<T> operator=(const scopedptr<T>& ap);//����������õ�ѡ��

//�����ģ��������������캯���͸�ֵ��������غ���

//ȱ�㣺���������Զ��ϳ�
*/