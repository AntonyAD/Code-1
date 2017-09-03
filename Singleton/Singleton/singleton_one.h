#pragma once
#include<iostream>
using namespace std;

//�������̰߳�ȫ
//�ڶ��߳�����¿��ܴ������ʵ��
class Singleton_one
{
public:
	static Singleton_one* GetInstance( int data)//����ʵ��
	{
		if (_singleton == NULL)
		{
			_singleton = new Singleton_one(data);
		}
		return _singleton;
	}

	static void DestoryInstance()
	{
		if (_singleton)
		{
			delete _singleton;
			_singleton = NULL;
		}
	}
	int Getdata()
	{
		return m_data;
	}

protected://��ֹ������ù��캯��
	Singleton_one(int data = 10) :m_data(data)
	{}
	Singleton_one(const Singleton_one& s);
	Singleton_one& operator=(const Singleton_one&);
private:
	static Singleton_one* _singleton;//��ľ�̬��Ա
	int m_data;
};

Singleton_one* Singleton_one::_singleton = NULL;//��ľ�̬��Ա�������ʼ��

void Test_singleton_one()
{
	Singleton_one* singleton = Singleton_one::GetInstance(20);
	cout << singleton->Getdata();
	Singleton_one::DestoryInstance();
}