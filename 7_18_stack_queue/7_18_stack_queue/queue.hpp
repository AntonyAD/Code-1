#pragma once
#include<iostream>
#include<queue>
using namespace std;


//ʹ����������ʵ��һ��ջ 
template <class T>
class Stack
{
public:
	Stack()
	{}

	void Push(const T& val)
	{
		q1.push(val);
	}

	void Pop()
	{
		size_t size = q1.size()-1;
		Move(q1,q2,size);
		q1.pop();
		Move(q2,q1,q2.size());
	}
	
	T& Top()
	{
		return q1.back();
	}

	size_t Size()
	{
		return q1.size();
	}

	bool Empty()
	{
		if (q1.empty())
			return true;
		return false;
	}

	~Stack()
	{}
private:
	void Move(queue<T>& s, queue<T>& d,size_t size)
	{
		while (size--)
		{
			d.push(s.front());
			s.pop();
		}
	}

private:
	queue<T> q1;//�M����
	queue<T> q2;//���Dվ
};


void Test1()
{
	Stack<int> s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);

	cout << s.Size()<<endl;
	s.Pop();
	cout << s.Size() << endl;
	if (s.Empty())
		cout << "NULL" << endl;
	else
		cout << "NOT NULL" << endl;

	int top = s.Top();

}