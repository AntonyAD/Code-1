#pragma once
#include<iostream>
using namespace std;

//const_cast:ǿ������ת����ȥ��const����

class Singleton_three
{
public:
	static Singleton_three* GetInstance()
	{
		return const_cast<Singleton_three*>(_singleton);
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

protected:
	Singleton_three(int data =1) :m_data(data)
	{}
	Singleton_three(const Singleton_three&);
	Singleton_three& operator=(const Singleton_three&);
private:
	int m_data;
	static const Singleton_three* _singleton;
};

const Singleton_three* Singleton_three::_singleton = new Singleton_three();
//��Ϊ��̬��ʼ���ڳ���ʼʱ��Ҳ���ǽ���������֮ǰ��
//�����߳��Ե��̷߳�ʽ����˳�ʼ�������Ծ�̬��ʼ��ʵ����֤���̰߳�ȫ�ԡ�
//������Ҫ��Ƚϸ�ʱ���Ϳ���ʹ�����ַ�ʽ���Ӷ�����Ƶ���ļ����ͽ�����ɵ���Դ�˷ѡ�

void Test_singleton_three()
{
	Singleton_three* singleton = Singleton_three::GetInstance();
	cout << singleton->Getdata() << endl;
	Singleton_three::DestoryInstance();
}