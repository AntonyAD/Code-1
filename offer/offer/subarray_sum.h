#pragma once
#include<iostream>
#include<vector>
using namespace std;

//���������������
int FindGreatestSumOfSubArray(vector<int> array)
{
	if (array.empty())
		return 0;
	int cur = array[0];//��ǰ��������
	int max = array[0];//����ֵ
	for (int i = 1; i < array.size(); i++)
	{
		cur += array[i];
		if (cur < array[i])//��ǰ��ֵ��i��Ӧ��Ԫ��ֵ��С������ǰԪ��ֵ����cur
			cur = array[i];//��ʼһ���µ�������
		if (cur>max)//��ǰֵ�������ֵ���ı����ֵ
			max = cur;
	}
	return max;
}


void Test_subarray()
{
	vector<int> v;
	v.push_back(6);
	v.push_back(-3);
	v.push_back(-2);
	v.push_back(7);
	v.push_back(-15);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);

	int ret = FindGreatestSumOfSubArray(v);
}