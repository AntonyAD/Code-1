#pragma once
#include<iostream>
#include<vector>
using namespace std;

//ֻ��ɽ�����ż���ֿ�
void reOrderArray1(vector<int> &array)
{
	if (array.empty())
		return;
	vector<int>::iterator it1 = array.begin();
	vector<int>::iterator it2 = array.end()-1;
	while (it1 < it2)
	{
		while ((*it1) % 2 != 0)
			it1++;
		while ((*it2) % 2 == 0)
			it2--;
		if (it1<=it2)
			swap(*it1,*it2);
	}
}
//1234567 -->1357246
void reOrderArray2(vector<int> &array)
{
	if (array.empty())
		return;
	vector<int> v1;//����
	vector<int>::iterator it1 = array.begin();
	while (it1!=array.end())//�������������ڸ���vector
	{
		if ((*it1) % 2 != 0)
			v1.push_back(*it1);
		it1++;
	}
	array.swap(v1);//��ԭ��vector�͸���vector����
	vector<int>::iterator it2 = v1.begin();
	while (it2!= v1.end())//������vector�е�ż��push��ԭ��vector
	{
		if ((*it2) % 2 == 0)
			array.push_back(*it2);
		it2++;
	}
}
void reOrderArray(vector<int> &array)
{
	if (array.empty())
		return;
	vector<int> v1;//����
	vector<int>::iterator it1 = array.begin();
	while (it1 != array.end())//�������������ڸ���vector
	{
		if ((*it1) % 2 != 0)
			v1.push_back(*it1);
		it1++;
	}
	it1 = array.begin();
	while (it1 != array.end())//������ż�����ڸ���vector
	{
		if ((*it1) % 2 == 0)
			v1.push_back(*it1);
		it1++;
	}
	array.swap(v1);//��ԭ��vector�͸���vector����
}

void reOrderArray3(vector<int> &array) {
	vector<int> b;
	for (int i = 0; i < array.size();){
		if (array[i] % 2 == 0)//��ż��push������vector����ż��ɾ��
		{
			b.push_back(array[i]);
			array.erase(array.begin() + i);
		}
		else{
			i++;
		}
	}
	array.insert(array.end(), b.begin(), b.end());//��ż�����뵽ԭ��vector
}


void Test_odd_even()
{
	vector<int> v;
	for (int i = 1; i < 8; i++)
		v.push_back(i);
	//v.push_back(2);
	//v.push_back(4);
	//v.push_back(6);
	//v.push_back(8);
	//v.push_back(10);
	//v.push_back(1);
	//v.push_back(3);
	//v.push_back(5);
	//v.push_back(7);
	//v.push_back(9);

	reOrderArray(v);
}