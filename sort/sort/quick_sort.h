#pragma once
#include<iostream>
//ð��+����+�ݹ�
int Quick_first(int arr[], int left, int right)
{
	int key = arr[left];
	int key_index = left;//�����׼ֵ�±꣬��󽻻�
	while (left < right)
	{
		while (left < right&&arr[right] >= key)//�ұߵ����ߣ����ܱ�֤�ҵ���С��Ԫ��
			--right;
		while (left < right&&arr[left] <= key)
			++left;
		std::swap(arr[left],arr[right]);
	}
	std::swap(arr[key_index],arr[left]);//����׼Ԫ����ָ��������Ԫ�ؽ���
	return left;
}

void Quick_sort(int arr[], int left, int right)
{
	if (left >= right)//�ݹ�ĳ���
		return;
	int mid = Quick_first(arr,left,right);
	Quick_sort(arr,left,mid-1);
	Quick_sort(arr,mid+1,right);
}

void Test_Quick()
{
	int arr[] = {4,2,1,6,8,9,3};
	int len = (sizeof(arr) / sizeof(arr[0]));
	Quick_sort(arr, 0, len-1);
}