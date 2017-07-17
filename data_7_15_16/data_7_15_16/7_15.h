#include <Windows.h>
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include<stdlib.h>


typedef int DataType;

#include<stdio.h>

typedef int DataType;

typedef struct Node
{
	DataType _data;
	struct Node* _pNext;
}Node, *PNode, **PPNode;



void InitList(PPNode pHead);                             // ��ʼ��������
void PushBack(PPNode pHead, DataType data);           // �ڵ������β������һ���ڵ�
void PopBack(PPNode pHead);                  // ɾ������������һ���ڵ�
void PushFront(PPNode pHead, DataType data);      // �ڵ������ͷ������ֵΪdata�Ľ��
void PopFront(PPNode pHead);           // ɾ��������ĵ�һ�����
Node* Find(PNode pHead, DataType data);     // �ڵ������в���ֵΪdata�Ľ�㣬�ҵ��˷��ظý��ĵ�ַ�����򷵻�NULL
void Insert(PPNode pHead, PNode pos, DataType data);     // �ڵ�����posλ�ú����ֵΪdata�Ľ��
void Erase(PPNode pHead, PNode pos);     // �ڵ�������ɾ��λ��Ϊpos�Ľ��
void Remove(PPNode pHead, DataType data);      // �Ƴ��������е�һ��ֵΪdata�Ľ��
void RemoveAll(PPNode pHead, DataType data);     // �Ƴ�������������ֵΪdata�Ľ��
size_t Size(PNode pHead);               // ��ȡ�������ܽ����ܸ���
int Empty(PNode pHead);         // �жϽ���Ƿ�Ϊ��
PNode Back(PNode pHead);          // ���ص���������һ������λ��
PNode Front(PNode pHead);       // ���ص�����ĵ�һ������λ��
Node* BuyNode(DataType data);      // ����һ���½ڵ�
void PrintList(PNode pHead);      // �����ӡ������
void DelFromTail2Head(PPNode pHead);//�������ٵ�����


///////////////������//////////////////////////////
void PrintFromTail2Head(PNode pHead);       // �����ӡ������
void DeleteNotTailNode(PNode pos);         // ɾ��������ķ�β���(���ܱ���������)

void PrintFromTail2Head(PNode pHead);   // ʹ�õݹ�ʵ�ִ�β��ͷ��ӡ������


void InsertNotHeadNode(PNode pos, DataType data);   // �ڵ������ͷ���ǰ������data
PNode FindMidNode(PNode pHead);     // ���ҵ�������м��㣬Ҫ��ֻ����һ������
PNode FindLastKNode(PNode pHead, size_t k);   // ���ҵ�����ĵ�����K����㣬Ҫ��ֻ����һ������
void BubbleSort(PNode pHead);    // ʹ��ð������Ե������������
/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
bool IsListCross(PNode L1, PNode L2);   // �ж������������Ƿ��ཻ(��������)
PNode CrossPoint(PNode L1, PNode L2);//�������󽻵�
PNode CrossPointLoop(PNode L1, PNode L2);//�����󽻵�

bool Isexistloop(PNode pHead);//�ж��Ƿ����
size_t Looplength(PNode pHead);//���ĳ���
PNode Loopport(PNode PHead);//�󻷵Ľ���



