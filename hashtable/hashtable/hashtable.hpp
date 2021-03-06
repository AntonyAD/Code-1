#pragma once
#include<vector>
#include<iostream>
using namespace std;
#include <math.h>
#include<string>
#include"POD.hpp"


enum State
{
	EMPTY,EXIST,DELETE
};
template <class K,class V>
struct HashNode
{
	pair<K, V> _hn;
	State _s;
	HashNode()
		:_s(EMPTY)
	{}
};
//1.第一次开辟空间的大小用非类型的类模板参数解决
//2.重新开辟空间的大小用获取质数函数解决
//3.二次探查
//4.类型(string)不同，可以用模板特化，类型萃取(想想，没尝试)
//string类型用字符串的长度来计算哈希地址
//用类型萃取识别string和内置类型

template <class K, class V, size_t SIZE = 11>
class Hashtable
{
	typedef pair<HashNode<K, V>*, bool> Pair;
public:
	Hashtable()
		:_size(0)
	{}
	Hashtable(size_t size)
		:_size(0)
	{
		_ht.resize(size);
	}
	bool Insert(const K& key,const V& value)
	{
		size_t i = 0;
		Checkcapacity();
		//计算存储位置 ----> 哈希函数
	    size_t Hashaddress = Hash_function(key, i++,TypeTraits<K>::__IsPODType());//类型萃取 1。

		//size_t Hashaddress = Hash_function(key,i++);//类型萃取 2 错误
		//size_t Hashaddress = Hash_function_str(key, i++);
		size_t index = Hashaddress;
		//找插入位置
		while (_ht[index]._s == EXIST)
		{
			HashNode<K, V>& elem = _ht[index];
			if (elem._hn.first == key)///????
				return false;
			//线性探查
			//++index;
			//二次探查
			//index = Hash_function(key,i++);//类型萃取 2 错误
			index = Hash_function(key, i++, TypeTraits<K>::__IsPODType());//类型萃取 1。
			//index = Hash_function_str(key, i++);

			if (index == _ht.size())//查找到最后一个位置后回到打一个位置，用取模每次都要计算，
				index = 0;
			//if (index == Hashaddress)//有了容量检测，就不会填满
				//return false;
		}
		//出了循环两种状态 EMPTY DELETE
		_ht[index]._hn.first = key;
		_ht[index]._hn.second = value;
		_ht[index]._s = EXIST;
		i = 0;
		++_size;
	}

	Pair Find(const K& key)
	{
		size_t i = 0;
		size_t Hashaddress = Hash_function(key, i++, TypeTraits<K>::__IsPODType());//类型萃取 1。
		//size_t Hashaddress = Hash_function(key, i++);//类型萃取 2 错误
		size_t index = Hashaddress;
		while (_ht[index]._s != EMPTY)
		{
			HashNode<K, V>& elem = _ht[index];
			if (elem._hn.first == key)
			{
				if (elem._s == EXIST)
					return Pair(&elem, true);
				else //if (elem._s == DELETE)
					return Pair(NULL, false);
			}
			//++index;
			index = Hash_function(key, i++, TypeTraits<K>::__IsPODType());//类型萃取 1。
			//index = Hash_function(key, i++);//类型萃取 2 错误
			if (index == _ht.size())
				index = 0;
			if (index == Hashaddress)
				return Pair(NULL, false);
		}
		return Pair(NULL, false);
	}

	bool Remove(const K& key)
	{
		Pair hn = Find(key);
		if (hn.second)
		{
			hn.first->_s = DELETE;
			--_size;
			return true;
		}
		return false;
	}
private:
	//size_t Hash_function(K key)
	//{
	//	return key%_ht.size();
	//}
	//size_t Hasn_function1(size_t size,size_t i)
	//{
	//	return (size + (size_t)pow(i, 2))%_ht.size();
	//}
	//////////////////////////////////////////////
	//////////////二次探查////////////////////

	//size_t Hash_function(K key,size_t i)//二次探查哈希函数
	//{
	//	return (key%_ht.size() + (size_t)pow(i, 2)) % _ht.size();
	//}
	////字符串：猜想1.用字符串的长度来计算哈希地址
	//size_t Hash_function_str(K key, size_t i)//字符串哈希函数
	//{
	//	string s(key);
	//	size_t str_key = s.length();
	//	return (str_key%_ht.size() + (size_t)pow(i, 2)) % _ht.size();
	//}
	///////////////////////////////////////////////////////
	/////////////////////类型萃取/////////////////////////
	//1.使用参数推导的类型萃取
	template <class K>
	size_t Hash_function(K key, size_t i,__TrueType)//二次探查哈希函数
	{
		return (key%_ht.size() + (size_t)pow(i, 2)) % _ht.size();
	}
	template <class K>
	size_t Hash_function(K key, size_t i, __FalseType)//字符串哈希函数
	{
		string s(key);
		size_t str_key = s.length();
		return (str_key%_ht.size() + (size_t)pow(i, 2)) % _ht.size();
	}


	////////////////////////////////////////////////////////
	////////有问题//不能用
	//2.使用萃取判断类型的Get函数判断是否是 POD类型来处理
	//template <class K>
	//size_t Hash_function(K key, size_t i)
	//{
	//	if (TypeTraits<K>::__IsPODType().Get())
	//	{
	//		return (key%_ht.size() + (size_t)pow(i, 2)) % _ht.size();
	//	}
	//	else
	//	{
	//		string s(key);
	//		size_t str_key = s.length();
	//		return (str_key%_ht.size() + (size_t)pow(i, 2)) % _ht.size();
	//	}
	//}


	void Checkcapacity()
	{
		if (_size == _ht.size())
			_ht.resize(SIZE);//用非类型的类模板参数解决
		else if (_size * 10 / _ht.size() == 7)//(_size / _ht.size() == 0.7)
		{//@荷载因子 = 有效元素个数/散列表长度
			size_t Newsize = Prime_num(_ht.size() * 2);//重新开辟空间的大小用获取质数函数解决
			Hashtable<K, V> ht(Newsize);
			for (size_t i = 0; i < _ht.size(); ++i)
			{
				if (_ht[i]._s == EXIST)
					ht.Insert(_ht[i]._hn.first, _ht[i]._hn.second);
			}
			//两个swap的运用
			swap(_size,ht._size);
			ht._ht.swap(_ht);
		}
	}

	//求质数
	size_t Prime_num(size_t size)
	{
		size_t Size = size;
		while (Is_prime(Size) == false)
			++Size;
		return Size;
	}
	bool Is_prime(size_t size)
	{
		size_t i = 2;
		while (i <= (sqrt(size)))
		{
			if (size%i == 0)
				return false;
			++i;
		}
		return true;
	}
private:
	vector<HashNode<K,V>> _ht;
	size_t _size;//有效元素个数
};

void Test()
{
	int a[] = {37,25,14,36,49,68,57,11};
	Hashtable<int, int> ht;
	for (size_t index = 0; index < sizeof(a) / sizeof(a[0]); ++index)
	{
		ht.Insert(a[index],index);
	}
	ht.Insert(24,8);
	ht.Insert(42, 9);
	//ht.Insert(66, 10);
	//ht.Insert(78, 11);
	pair<HashNode<int,int>*, bool> h = ht.Find(14);
	pair<HashNode<int, int>*, bool> h1 = ht.Find(36);

	if (ht.Remove(14))
		cout << "True" << endl;
	else
		cout << "False" << endl;
}

//void Test1()
//{
//	string str = "abcdefghijklmn";
//	Hashtable<char, char> ht;
//	for (size_t index = 0; index < str.length(); ++index)
//	{
//		ht.Insert(str.at(index), str.at(index));
//	}
//	//ht.Insert(24, 8);
//}

void Test2()
{
	string s[] = { "abc","cde","fgh","ijk" };
	Hashtable<string, int> ht;
	for (size_t index = 0; index <sizeof(s) / sizeof(s[0]); ++index)
	{
		ht.Insert(s[index],index);
	}

	pair<HashNode<string, int>*, bool> h = ht.Find("abc");
	pair<HashNode<string, int>*, bool> h1 = ht.Find("fgh");

	if (ht.Remove("cde"))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	
}