#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>


void check(int *p)
{
	int i = 0;
	for(i=0; i<6; i++)
	{
		if(p[i]<60)
		{
			printf("%d  ",p[i]);
		}
	}
	printf("\n");
}

//void *malloc(unsigned int size)
//void *calloc(unsigned n,unsigned sise)
//void *realloc(void*p,unsigned int size)
//void free(void *p)
int main()
{
	int i,*p1,*p2;
	/*p1 = (int *) calloc(5,sizeof(int));*/       //malloc(5*sizeof(int))
    p1 = calloc(5,sizeof(int));      //p1λ����ָ�룬�Զ��л�
	p2 = realloc(p1,6*sizeof(int));       //���·���p1��p1֮ǰ����malloc �� calloc���䶯̬�ռ䣩��ָ��Ķ�̬�ռ�Ĵ�С
	for(i=0; i<6; i++)
	{
		scanf("%d",p1+i);
	}
	/*free(p2);*/     //�ͷ�ָ�����p2��ָ��Ķ�̬�ռ�
	check(p2);
	free(p2);
	system("pause");
	return 0;
}