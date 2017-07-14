#include<iostream>
using namespace std;
#define DATATYPE int
//7-13��Ŀ��
//1.�������⡿--�ϲ��������������ϲ��Ժ��������������//complete
//2.�������⡿--ʵ��1 + 2 + 3... + n��Ҫ����ʹ�ó˳�����
//ѭ���������жϡ�ѡ����صĹؼ��֡���������ж��ֽⷨ��
//��ҿ��Ծ���ȥ˼������������ŵĽⷨʱ�临�Ӷ���O(1����
//��ҿ���ȥ����ʵ�֣�


//7-14��Ŀ
//1.�������⡿--����/��ת������+���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 
//2.�������⡿--ʵ��һ��Add����������������ӣ����ǲ���ʹ�� + �� - ��*�� / 
//�������������ps : Ҳ������++��--�ȵ�


//��Ҫ��ϰ֪ʶ��
//1.new/delete/new[]/delete[]/malloc/calloc/realloc/free
//2.˳�������
//3.���ݽṹʱ�临�ӶȺͿռ临�Ӷȼ���
//4.struct�������塢enum
//5.



struct Node
{
	DATATYPE data;
	struct Node* _next;
};


void push(struct Node** head, DATATYPE data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	if (new_node == NULL)
	{
		cout << "malloc" << endl;
	}

	new_node->data = data;
	new_node->_next = *head;

	*head = new_node;
	//free(new_node);
}

//�ݹ�ϲ�

//�ϲ�������
/*
struct Node* SortedMerge(struct Node* head1, struct Node* head2)
{
	struct Node* end = NULL;
	struct Node* ret = NULL;
	//�ж���������ĳһ���Ƿ�Ϊ��
	if (head1 == NULL)
	{
		return head2;
	}
	else if (head2 == NULL)
	{
		return head1;
	}
	//end����ֵ
	if (head1->data <= head2->data)
	{
		end = head2;
		head2 = head2->_next;
	}
	else
	{
		end = head1;
		head1 = head1->_next;
	}
	//������������
	ret = end;
	while (head1&&head2)
	{
		
		//31  42
		if (head1->data <= head2->data)
		{
			end->_next = head2;
			head2 = head2->_next;
		}
		else
		{
			end->_next = head1;
			head1 = head1->_next;
		}
		end = end->_next;
	}
	//��ѭ�����ж����������Ǹ���Ϊ�վ������ں���
	if (head1)
	{
		end->_next = head1;
	}
	if (head2)
	{
		end->_next = head2;
	}
	return ret;
}
*/

//2
struct Node* SortedMerge(struct Node* head1, struct Node* head2)
{
	struct Node* ret = NULL;
	//�ж���������ĳһ���Ƿ�Ϊ��
	if (head1 == NULL)
	{
		return head2;
	}
	else if (head2 == NULL)
	{
		return head1;
	}
	//end����ֵ
	if (head1->data <= head2->data)
	{
		ret = head2;
		ret->_next = SortedMerge(head1,head2->_next);
	}
	else
	{
		ret = head1;
		ret->_next = SortedMerge(head1->_next, head2);
	}
	return ret;
}

//���á���ת������
//1.ͷ�巨����
void Inverse1(struct Node** head)
{
	struct Node* head1 = *head;
	struct Node* ret = NULL;
	while (head1)
	{
		push(&ret,head1->data);
		head1 = head1->_next;
	}
	*head = ret;
}
//2.�������
void Inverse2(struct Node** head)
{
	struct Node* Pre = NULL;
	struct Node* Cur = *head;
	struct Node* Next = NULL;

	while (Cur)
	{
		Next = Cur->_next;
		Cur->_next = Pre;
		Pre = Cur;
		Cur = Next;
	}
	*head = Pre;
}
//3.ֵ���� not complete
void Inverse3(struct Node** head)
{
	struct Node* start = *head;
	struct Node* last = *head;
}

//���ҵ�����ĵ�����k�����
struct Node Find_k(struct Node* head,size_t k)
{
	size_t n = 0;
	size_t sep = 0;
	struct Node* first = head;
	struct Node ret ;
	while (first)
	{
		n++;
		first = first->_next;
	}
	//sep = n - k - 1;//��0��ʼ
	sep = n - k;//��1��ʼ
	while (sep--)
	{
		head = head->_next;
	}
	ret = *head;
	return ret;
}


void print(struct Node* head)
{
	//struct Node* _head = head;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->_next;
	}
	cout << endl;
}



void test()
{
	struct Node* head1 = NULL;
	struct Node* head2 = NULL;
	struct Node* head3 = NULL;
	push(&head1,1);
	//push(&head1, 2);
	push(&head1, 3);
	//push(&head1, 4);
	print(head1);
	//push(&head2, 5);
	//push(&head2, 6);
	push(&head2, 2);
	push(&head2, 4);
	print(head2);

	head3 = SortedMerge(head1,head2);
	print(head3);
}

void test2()
{
	struct Node* head1 = NULL;
	struct Node ret;
	push(&head1, 1);
	push(&head1, 2);
	push(&head1, 3);
	push(&head1, 4);
	push(&head1, 5);
	print(head1);
	//Inverse1(&head1);
	ret = Find_k(head1,2);
	cout << ret.data << endl;
}


int Add(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	int first = a^b;
	int second = a&b;
	return Add(first,second);
}



