#pragma once
#include<iostream>
#include<vector>
using namespace std;


bool duplicate(int numbers[], int length, int* duplication) 
{
	if (length <= 0)
		return false;
	int max = 0;
	int i = 0;
	for (i = 0; i < length; i++)//Ѱ������������ֵ
	{
		if (numbers[i] > max)
			max = numbers[i];
	}
	vector<int> v(max+1,0);//��������
	for (i = 0; i < length; i++)//��numbers��Ԫ�ض�Ӧ��vector�е��±����++
	{
		v[numbers[i]]++;
	}

	for (i = 0; i < length; i++)//Ѱ�ҳ��ִ�������1��
	{
		if (v[i]>1)
		{
			*duplication = i;
			return true;
		}
	}
	return false;
}



void Test_array_repeat()
{
	int array[] = { 2, 3, 1, 0, 2, 5, 3 };
	int j = 0;
	if (duplicate(array, sizeof(array) / sizeof(array[0]), &j))
		cout << "����" << endl;
	else
		cout << "������" << endl;
}