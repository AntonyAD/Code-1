#pragma once
#include<iostream>
using namespace std;
//Ĭ�ϴ�1-n�������е�1�ĸ���
int NumberOf1Between1AndN_Solution(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = i;
		while (tmp)
		{
			if (tmp % 10 == 1)
				count++;
			tmp /= 10;
		}
	}
	return count;
}
//��start��end֮���������1�ĸ���
int NumberOf1Between1AndN_Solution(int start,int end)
{
	int count = 0;
	for (int i = start; i <= end; i++)
	{
		int tmp = i;
		while (tmp)
		{
			if (tmp % 10 == 1)
				count++;
			tmp /= 10;
		}
	}
	return count;
}

void Test_int_one_count()
{
	int ret = NumberOf1Between1AndN_Solution(100,1300);
}