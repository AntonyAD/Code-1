#include"7_15.h"

void InitList(PPNode pHead) // ��ʼ��������
{
	*pHead = NULL;
}
Node* BuyNode(DataType data)      // ����һ���½ڵ�
{
	PNode _node = (PNode)malloc(sizeof(Node));
	if (NULL == _node)
		exit(-1);
	_node->_data = data;
	_node->_pNext = NULL;
	return _node;
}
void PushBack(PPNode pHead, DataType data)          // �ڵ������β������һ���ڵ�
{
	assert(pHead);
	if (NULL == *pHead)
	{
		*pHead = BuyNode(data);
	}
	else
	{
		PNode pnode = *pHead;
		while (pnode->_pNext)
		{
			pnode = pnode->_pNext;
		}
		pnode->_pNext = BuyNode(data);
	}
}

void PopBack(PPNode pHead)    // ɾ������������һ���ڵ�
{
	assert(pHead);
	if (NULL == *pHead)
	{
		return;
	}
	else
	{
		PNode pnode = *pHead;
		while (pnode->_pNext->_pNext)
		{
			pnode = pnode->_pNext;
		}
		free(pnode->_pNext);
		pnode->_pNext = NULL;
	}
}
void PushFront(PPNode pHead, DataType data)      // �ڵ������ͷ������ֵΪdata�Ľ��
{
	assert(pHead);
	if (NULL == *pHead)
	{
		*pHead = BuyNode(data);
	}
	else
	{
		PNode pnode = BuyNode(data);
		pnode->_pNext = *pHead;
		*pHead = pnode;
	}
}
void PopFront(PPNode pHead)         // ɾ��������ĵ�һ�����
{
	assert(pHead);
	if (NULL == *pHead)
	{
		return;
	}
	else
	{
		PNode pnode = (*pHead)->_pNext;
		free(*pHead);
		*pHead = pnode;
	}

}
Node* Find(PNode pHead, DataType data)     // �ڵ������в���ֵΪdata�Ľ�㣬�ҵ��˷��ظý��ĵ�ַ�����򷵻�NULL
{
	//if (NULL != pHead)
	//{
	//	PNode pnode = pHead;
	//	while (pnode)
	//	{
	//		if (pnode->_data == data)
	//			return pnode;
	//		pnode = pnode->_pNext;
	//	}
	//}
	//return NULL;

	if (NULL != pHead)
	{
		PNode pnode = Find(pHead->_pNext, data);
		if (pnode)
			return pnode;
		if (pHead->_data == data)
			return pHead;
	}
	return NULL;
}
void Insert(PPNode pHead, PNode pos, DataType data)     // �ڵ�����posλ�ú����ֵΪdata�Ľ��
{
	assert(pHead);
	PNode pnode = *pHead;
	PNode _pnode = NULL;
	if (NULL == *pHead || NULL == pos)
		return;
	while (pnode != pos)
		pnode = pnode->_pNext;
	_pnode = BuyNode(data);
	_pnode->_pNext = pnode->_pNext;
	pnode->_pNext = _pnode;
}
void Erase(PPNode pHead, PNode pos)   // �ڵ�������ɾ��λ��Ϊpos�Ľ��
{
	assert(pHead);
	PNode pnode = *pHead;
	if (NULL == *pHead || NULL == pos)
		return;
	while (pnode != pos)
		pnode = pnode->_pNext;
	PNode _pnode = pnode->_pNext->_pNext;
	pnode->_data = pnode->_pNext->_data;
	free(pnode->_pNext);
	pnode->_pNext = _pnode;
}
void Remove(PPNode pHead, DataType data)      // �Ƴ��������е�һ��ֵΪdata�Ľ��
{
	assert(pHead);
	Erase(pHead, Find(*pHead, data));
}
void RemoveAll(PPNode pHead, DataType data)     // �Ƴ�������������ֵΪdata�Ľ��
{
	assert(pHead);
	PNode pnode = NULL;
	if (NULL == *pHead)
		return;
	pnode = *pHead;
	while (pnode->_pNext)
	{
		if (pnode->_data == data)
		{
			Erase(&pnode, pnode);
		}
		else
		{
			pnode = pnode->_pNext;
		}
	}
}
size_t Size(PNode pHead)              // ��ȡ�������ܽ����ܸ���
{
	size_t count = 0;
	if (NULL == pHead)
		return 0;
	while (pHead)
	{
		++count;
		pHead = pHead->_pNext;
	}
	return count;
}
int Empty(PNode pHead)        // �ж������Ƿ�Ϊ��
{
	if (NULL == pHead)
		return 0;
	else
		return -1;
}
PNode Back(PNode pHead)          // ���ص���������һ������λ��
{
	if (NULL == pHead)
		return NULL;
	while (pHead->_pNext)
		pHead = pHead->_pNext;
	return pHead;
}
PNode Front(PNode pHead)       // ���ص�����ĵ�һ������λ��
{
	if (NULL == pHead)
		return NULL;
	return pHead;
}

void PrintList(PNode pHead)      // �����ӡ������
{
	while (NULL != pHead)
	{
		printf("%d ", pHead->_data);
		pHead = pHead->_pNext;
	}
	printf("\n");
}


void PrintFromTail2Head(PNode pHead)//�ݹ������ӡ������
{
	if (NULL != pHead)
	{
		if (pHead->_pNext != NULL)
		{
			PrintFromTail2Head(pHead->_pNext);
		}
	}
	printf("%d ", pHead->_data);
}

void DelFromTail2Head(PPNode pHead)
{
	assert(pHead);
	PNode pnode = *pHead;
	if (NULL != pnode)
	{
		if (NULL != pnode->_pNext)
		{
			DelFromTail2Head(&(pnode->_pNext));
		}
		free(pnode);
		pnode = NULL;
	}
}



bool Isexistloop(PNode head)//�ж������Ƿ����
{
	assert(head);
	PNode fast = head;
	PNode slow = head;

	while (fast&&fast->_pNext)
	{
		fast = fast->_pNext->_pNext;
		slow = slow->_pNext;
		if (fast == slow)
			return true;
	}
	return false;
}

size_t Looplength(PNode head)
{
	assert(head);
	PNode fast = head;
	PNode slow = head;
	size_t length = 1;
	//�ҵ�����
	while (fast&&fast->_pNext)
	{
		fast = fast->_pNext->_pNext;
		slow = slow->_pNext;
		if (fast == slow)
			break;
	}
	//�ӽ��㿪ʼ����
	PNode cur = fast->_pNext;
	while (cur != fast)
	{
		length++;
		cur = cur->_pNext;
	}
	return length;
}
PNode Loopport(PNode head)
{
	assert(head);
	PNode fast = head;
	PNode slow = head;
	
	while (fast&&fast->_pNext)
	{
		fast = fast->_pNext->_pNext;
		slow = slow->_pNext;
		if (fast == slow)
			break;
	}
	PNode cur = head;
	while (cur != fast)
	{
		cur = cur->_pNext;
		fast = fast->_pNext;
	}
	return cur;
}


bool IsListCross(PNode L1, PNode L2)//�ж����������Ƿ��ཻ����������
{
	if ((L1 == NULL) || (L2 == NULL))
		return false;
	while (L1->_pNext)
		L1 = L1->_pNext;
	while (L2->_pNext)
		L2 = L2->_pNext;
	return L1 == L2;
}

PNode CrossPoint(PNode L1, PNode L2)//�������󽻵�
{
	//���������ĳ���
	int length = 0;
	int length1 = 0;
	int length2 = 0;
	PNode head1 = L1;
	PNode head2 = L2;
	while (head1)
	{
		length1++;
		head1 = head1->_pNext;
	}
	while (head2)
	{
		length2++;
		head2 = head2->_pNext;
	}
	//��������֮��
	length = abs(length1-length2);
	//��������(��)��
	if (length1 > length2)
	{
		while (length--)
			L1 = L1->_pNext;
		//������Ϊ����
		while (L1 != L2)
		{
			L1 = L1->_pNext;
			L2 = L2->_pNext;
		}
		return L1;
	}
	else
	{
		while (length--)
			L2 = L2->_pNext;
		while (L1 != L2)
		{
			L1 = L1->_pNext;
			L2 = L2->_pNext;
		}
		return L2;
	}
}
PNode CrossPointLoop(PNode L1, PNode L2)//���������������󽻵�
{
	//������������ڵ�
	PNode CrossPortL1 = Loopport(L1);
	PNode CrossPortL2 = Loopport(L2);
	PNode Ret = NULL;
	
	//�ж�������ڵ��Ƿ����
	if (CrossPortL1 == CrossPortL2)
	{
		//��ȣ���Y�󽻵㣬��ԭ
		PNode Last = CrossPortL1->_pNext;
		CrossPortL1->_pNext = NULL;
		Ret = CrossPoint(L1,L2);
		CrossPortL1->_pNext = Last;
	}
	else
	{
		//����ȣ�����һ������Ļ��ĳ��ȿ��Ƿ�����������һ���������ڵ�
		size_t len = Looplength(L1);
		PNode next = CrossPortL1->_pNext;
		while (len--)
		{
			if (next == CrossPortL2)
			{
				Ret = CrossPortL2;
				break;
			}
			next = next->_pNext;
		}
		if (len <= 0)
			return NULL;
	}
	return Ret;
}


void Test()
{
	PNode L1 = NULL;
	PNode L2 = NULL;
	PushBack(&L1, 1);
	PushBack(&L1, 2);
	PushBack(&L1, 3);
	PushBack(&L1, 4);
	PushBack(&L2, 5);
	PushBack(&L2, 6);
	PushBack(&L2, 7);
	PushBack(&L2, 8);
	PushBack(&L2, 9);
	
	size_t s1 = Size(L1);
	size_t s2 = Size(L2);
	size_t i = 2;
	PNode head1 = L1;
	PNode head2 = L2;
	while (i--)
		head1 = head1->_pNext;
	i = 2;
	while (i--)
		head2 = head2->_pNext;
	head1->_pNext = head2;
	PNode JJ = head2;
	while (head2->_pNext)
		head2 = head2->_pNext;
	head2->_pNext = JJ;


	//if (IsListCross(L1, L2))
	//	printf("Yes\n");
	//else
	//	printf("Not\n");
	if (Isexistloop(L1))
		printf("Yes\n");
	else
		printf("Not\n");
	//PNode ret = CrossPoint(L1,L2);
	PNode ret = CrossPointLoop(L1,L2);
	size_t oo = Looplength(L1);
	size_t oo1 = Looplength(L2);

}


int main()
{
	Test();
	return 0;
}