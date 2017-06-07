#include <utility>
#include<iostream>
using namespace std;

template <class K,int M>
struct BTreeNode
{
	K _keyarray[M];//�ؼ���   ������һ��
	BTreeNode<K, M>* _childarray[M + 1];//����
	BTreeNode<K, M>* _parent;//˫��
	size_t _size;//��ЧԪ�ظ���
	BTreeNode()
		:_parent(NULL)
		, _size(0)
	{
		for (size_t idx = 0; idx < M + 1; ++idx)
			_childarray[idx] = NULL;
	}
};

//���룺
//	1.����
//	2.�ǿ�
//			1.�жϲ���key������key�Ĵ�С��Ѱ�Ҳ���λ��----->find
//			2.����
//			3.�ж�_size��M�Ĵ�С��С�ڲ�����ȷ����true;���ڽ��з���
//			4.���ѣ�1.���м�λ��
//					2.�����½ڵ㣬���Ұ벿�������½ڵ�
//					3.�м�Ԫ�أ�1.˫�״���
//								2.˫�ײ����� -->�����½ڵ㣬���м�Ԫ�������½ڵ㣬���º���


template <class K,int M>
class BTree
{
	typedef BTreeNode<K, M> Node;
	typedef pair<Node*, int> Pair;
public:
	BTree()
		:_pRoot(NULL)
	{}

	bool Insert(const K& key)
	{
		if (NULL == _pRoot)
		{
			_pRoot = new Node;
			_pRoot->_keyarray[0] = key;
			_pRoot->_size = 1;
			return true;
		}
		else
		{
			pair<Node*,int> pCur = _Find(key);
			if (pCur.second > -1)
				return false;

			Node* pNode = pCur.first;
			K _k = key;
			Node* childarray = NULL;

			while (true)
			{
				_Insert(pNode, _k, childarray);


				if (pNode->_size < M)
					return true;
				//��Ҫ�Խڵ���з���
				Node* pNewNode = new Node;
				size_t mid = M / 2;
				size_t index = 0;
				size_t idx = 0;

				//����Ԫ�غͺ���ָ�뵽pNewNode
				for (idx = mid + 1; idx<pNode->_size; ++idx)
				{
					pNewNode->_keyarray[index] = pNode->_keyarray[idx];
					pNewNode->_childarray[index] = pNode->_childarray[idx];
					if (pNode->_childarray[idx])
					{
						pNode->_childarray[idx]->_parent = pNewNode->_childarray[index];
						pNode->_childarray[idx] = NULL;
					}
					pNewNode->_size++;
					pNode->_size--;
					index++;
				}

				pNewNode->_childarray[index] = pNode->_childarray[idx];
				if (pNode->_childarray[idx])
				{
					pNode->_childarray[idx]->_parent = pNewNode->_childarray[index];
					pNode->_childarray[idx] = NULL;
				}
				pNode->_size = pNode->_size - pNewNode->_size;

				//�жϸýڵ��Ƿ�Ϊ���ڵ�
				if (pNode->_parent == NULL)
				{
					_pRoot = new Node;
					_pRoot->_keyarray[0] = pNode->_keyarray[mid];

					_pRoot->_childarray[0] = pNode;
					pNode->_parent = _pRoot;
					_pRoot->_childarray[1] = pNewNode;
					pNewNode->_parent = _pRoot;
					_pRoot->_size++;
					return true;
				}
				else
				{
					_k = pNode->_keyarray[mid];
					pNode = pNode->_parent;
					childarray = pNewNode;
				}
			}
		}
	}
private:
	Pair _Find(const K& key)
	{
		if (NULL == _pRoot)
			return Pair(NULL, -1);
		else
		{
			Node* pCur = _pRoot;
			Node* parent = NULL;
			while (pCur)
			{
				size_t i = 0;
				while (i < pCur->_size)
				{
					if (key < pCur->_keyarray[i])
					{
						break;
					}
					else if (key > pCur->_keyarray[i])
					{
						++i;
					}
					else
					{
						return Pair(pCur, i);
					}
				}
				parent = pCur;
				pCur = pCur->_childarray[i];
			}
			return Pair(parent , -1);
		}
	}
	void _Insert(Node*& pNode, const K& key, Node* pSub)
	{
		int end = pNode->_size - 1;
		while (end > -1)
		{
			if (pNode->_keyarray[end] > key)
			{
				pNode->_keyarray[end + 1] = pNode->_keyarray[end];
				pNode->_childarray[end + 2] = pNode->_childarray[end + 1];
			}
			else
				break;
			end--;
		}
		pNode->_keyarray[end + 1] = key;
		pNode->_childarray[end + 2] = pSub;
		if (pSub)
			pSub->_parent = pNode;
		pNode->_size++;
	}

private:
	Node* _pRoot;
};

void Test()
{
	int a[] = {53,75,139,49,145,36,101};

	BTree<int, 3> b;
	for (size_t index = 0; index < sizeof(a) / sizeof(a[0]); ++index)
	{
		b.Insert(a[index]);
	}

}