//5. дһ���������ز����������� 1 �ĸ���
//���磺 15       0000 1111       4 �� 1
//����ԭ�ͣ�
//int  count_one_bits(unsigned int value)
//{
//	// ���� 1��λ��
//}
#include <stdio.h>
#include <Windows.h>

int count_one_bits(unsigned int value)
{
	int count = 0;
    while(value)
	{
		if(value%2 == 1)        //
		{
			count++;
		}
		value = value/2;
	}
	return count;
}


int main()
{
	int ret = 0;
	unsigned int m = 0;
	scanf("%d",&m);
	ret = count_one_bits(m);
	printf("count = %d\n",ret);
	system("pause");
	return 0;
}