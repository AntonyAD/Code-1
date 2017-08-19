#pragma once
#include<iostream>

void Select_sort(int arr[], int size)
{
	if (NULL == arr && 0 == size)
		return;
	int minindex = 0;
	for (int i = 0; i < size; ++i)
	{
		minindex = i;//ÿ�˼���arr[i]��С����i+1��ʼ����С��
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[j] < arr[minindex])
				minindex = j;
		}
		if (minindex != i)//һ�����꣬�����Сֵ������������i��˵���ҵ��˸�С�ģ�����
			std::swap(arr[i], arr[minindex]);
	}
}

void Test_select()
{
	int arr[] = {5,2,7,1,3,4,12};
	Select_sort(arr,sizeof(arr)/sizeof(arr[0]));
}