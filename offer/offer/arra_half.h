#pragma once
#include<iostream>
#include<vector>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) 
{
	if (numbers.empty())
		return -1;
	int max = 0;//���ֵ
	int min = numbers.size() >> 1;//�����һ��
	vector<int>::iterator it = numbers.begin();
	while (it != numbers.end())//Ѱ�����ֵ
	{
		if (*it > max)
			max = *it;
		it++;
	}
	vector<int> v(max+1,0);//����vector����ʼ��Ϊ0
	it = numbers.begin();
	while (it != numbers.end())//����ԭ��vector���ڸ���vector��Ӧ�±����ֵ++
	{
		v[*it++]++;
	}
	for (int i = 0; i < v.size(); i++)//��������vector��Ѱ�ҳ��ִ����������������±�
	{
		if (v[i]>min)
			return i;
	}
	return 0;
}
//1, 2, 3, 2, 2, 2, 5, 4, 2
void Test_array_min()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(2);
	MoreThanHalfNum_Solution(v);
}