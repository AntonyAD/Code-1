#include<iostream>
using namespace std;

template <class T>
class ShareStack
{
public:
	ShareStack(size_t capacity = 10)//����һ������ջ��Ĭ������Ϊ10
		:_capacity(capacity)
	{
		_pData = new T[_capacity];
		_stack1 = 0;
		_stack2 = _capacity - 1;
		_top1 = 0;
		_top2 = _capacity - 1;
	}
	void Push1(const T& x)//ջ1����Ԫ��
	{
		if (_top1 != _top2)
			_pData[_top1++] = x;
	}
	void Push2(const T& x)//ջ2����Ԫ��
	{
		if (_top1 != _top2)
			_pData[_top2--] = x;
	}
	void Pop1()//ջ1ɾ��Ԫ��
	{
		--_top1;
	}
	void Pop2()//ջ2ɾ��Ԫ��
	{
		++_top2;
	}

	T& top1()//����ջ��Ԫ��
	{
		return _pData[_top1-1];
	}
	const T& top1() const
	{
		return _pData[_top1-1];
	}
	T& top2()
	{
		return _pData[_top2+1];
	}
	const T& top2() const
	{
		return _pData[_top2+1];
	}
	size_t size1() const//������ЧԪ�ظ���
	{
		return _top1;
	}
	size_t size2() const
	{
		return _capacity - _top2 - 1;
	}
	bool empty()const//�п�
	{
		return _top1 == _top2 ? true : false;
	}


	~ShareStack()//����
	{
		if (_pData)
		{
			delete[] _pData;
			_pData = NULL;
			_capacity = 0;
			_stack1 = 0;
			_stack2 = 0;
			_top1 = 0;
			_top2 = 0;
		}
	}
private:
	T* _pData;
	size_t _capacity;
	size_t _stack1;
	size_t _stack2;
	size_t _top1;
	size_t _top2;
};


//����
int main()
{
	ShareStack<int> ss(12);
	ss.Push1(1);
	ss.Push1(2);
	ss.Push1(3);
	ss.Push1(4);
	ss.Push1(5);
	ss.Push1(6);
	ss.Push1(7);
	ss.Push1(8);

	ss.Push2(12);
	ss.Push2(11);
	ss.Push2(10);
	ss.Push2(9);
	cout << ss.size1() << endl;
	cout << ss.size2() << endl;

	cout << ss.top1() << endl;
	cout << ss.top2() << endl;
	//ss.Pop1();
	//ss.Pop2();
	cout << ss.size1() << endl;
	cout << ss.size2() << endl;
	if (ss.empty())
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "����" << endl;
	}
	return 0;
}