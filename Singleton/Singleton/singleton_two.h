#pragma once
#include<iostream>
using namespace std;
#include<mutex>
#include<thread>

//�̰߳�ȫ
// 1.����ռ� 2.���ù��캯�� 3.��ֵ
// �����������Ż����ܻ��2��3����ָ�����ţ��������ܻᵼ��
// �߲��������£������̻߳�ȡ��δ���ù��캯����ʼ���Ķ���
// ���¼����ڴ�դ�����д�����ֹ����������դ������ĸ�ֵ
// ���ڴ�դ��֮ǰ
class Singleton_two
{
public:
	static Singleton_two* GetInstance(int data = 2)
	{
		//����������m_Instance == NULL���жϣ��ǽ����Java�ĵ���ģʽʵ��ʱ��
		//ʹ�õ���ν�ġ�˫���������ơ���Ϊ����һ�μ����ͽ�������Ҫ������Ӧ�Ĵ��۵ģ�
		//�����������жϣ��Ϳ��Ա����μ��������������ͬʱҲ��֤���̰߳�ȫ
		if (_singleton == NULL)
		{
			lock_guard<mutex> lock(_mx);
			//_mx.lock();
			if (_singleton == NULL)
			{
				_singleton = new Singleton_two(data);
				
			}
			//_mx.unlock();
		}
		return _singleton;
	}
	
	static void DestoryInstance()
	{
		lock_guard<mutex> lock(_mx);
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
	Singleton_two(int data = 1) :m_data(data)
	{}
	Singleton_two(const Singleton_two& s);
	Singleton_two& operator=(Singleton_two&);
private:
	static Singleton_two* _singleton;
	static mutex _mx;
	int m_data;
};

Singleton_two* Singleton_two::_singleton = NULL;
mutex Singleton_two::_mx;//

void Test_singleton_two()
{
	Singleton_two* singleton = Singleton_two::GetInstance(22);
	cout<<singleton->Getdata() << endl;
	Singleton_two::DestoryInstance();
}