#pragma once

#include<vector>
#include<iostream>

class Bitmap
{
public:
	Bitmap(size_t size = 1024)
	{
		_vt.resize((size>>5)+1);
	}

	//����ĳ������λ��1
	void Set(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		_vt[index] |= (1<<pos);
	}

	//����ĳ������λ��Ϊ0
	void Reset(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		_vt[index] &= (~(1 << pos));
	}

	//�ж�һ�����Ƿ����

	bool Exist(size_t num)
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		return _vt[index] & (1 << pos);
	}

private:
	std::vector<size_t> _vt;
};


