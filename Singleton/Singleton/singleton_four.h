#pragma once
#include<iostream>
using namespace std;

//new��delete��Ҫ�ɶ�ʹ�ã���ʱ������ǵ�delete������ڴ�й©
//����ģʽ�л�ȡʵ��������ͷ�ʵ����������������Ҫ�ɶԴ��ڣ�Ҳ������
//�������·�ʽ���������ͷ�
class Singleton_four
{
public:
	static Singleton_four* GetInstance()
	{
		static Singleton_four _singleton;//������̬����,��̬ȫ�ֹ���
		return &_singleton;
	}
	int Getdata()
	{
		return m_data;
	}

protected:
	Singleton_four() :m_data(10)
	{}
	Singleton_four(const Singleton_four&);
	Singleton_four& operator=(const Singleton_four&);
private:
	int m_data;
};


void Test_singleton_four()
{
	Singleton_four* singleton = Singleton_four::GetInstance();
	cout << singleton->Getdata() << endl;
}