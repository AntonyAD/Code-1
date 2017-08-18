#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>


class String
{
public:
	String(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		if (*str == 0)
			*_str = '\0';
		else
			strcpy(_str, str);
	}

	String(const String& s)
	{
		_str = s._str;
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			if (_str)
				delete[] _str;
			_str = s._str;
		}
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = 0;
		}
	}

private:
	char* _str;
};

//����������ָ�����ʱ����������͸�ֵ���������ֻ����ֵ����(ǳ����)����������ָ��ͬһ����
//�棬��������ʱ�ÿռ䱻�ͷ������Σ���˳��������
void Test_shallow_copy()
{
	String s1("hello wgb");
	String s2(s1);
	String s3 = s2;
	String s4;
	s4 = s3;
}