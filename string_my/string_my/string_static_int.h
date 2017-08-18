#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>


class String_static_int
{
public:
	String_static_int(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		if (*str == 0)
			*_str = '\0';
		else
			strcpy(_str, str);
		++_count;
	}

	String_static_int(const String_static_int& s)
	{
		_str = s._str;
		++(s._count);
		_count = s._count;
	}

	String_static_int& operator=(const String_static_int& s)
	{
		if (this != &s)
		{
			if (_str)
				delete[] _str;
			_str = s._str;
			++(s._count);
			_count = s._count;
		}
		return *this;
	}

	~String_static_int()
	{
		if (_str)
		{
			if (--_count == 0)
			{
				delete[] _str;
				_str = 0;
			}
		}
	}

private:
	static int _count;
	char* _str;
};
int String_static_int::_count = 0;//��ľ�̬��Ա��ʼ��

void Test_static_count()
{
	String_static_int s1("hello wgb");
	String_static_int s2(s1);
	String_static_int s3 = s2;
	String_static_int s4;
	s4 = s3;
}

//�������ĸ����󣬼�����ȴ��5��
//��Ϊ���������ྲ̬��Ա�����ж����������Զ����޸ģ�
//��ָ��ͬһ��ռ�Ķ��󶼽�����++�����Ե��´���