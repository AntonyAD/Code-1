#include <stdio.h>
#include <Windows.h>
#include <assert.h>


char* my_strcpy(char *dest,const char *src)       //char* ��ʽ����    const���η�ֹ�����ڲ��ı�ֵ����������
{
	char* ret = dest;
	assert(dest != NULL);    //���ԣ��������ֵ��
	assert(src!= NULL);
	while(*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
    *dest = *src;
	return ret;
}


//char* my_strcpy(char *dest,const char *src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while(*dest++ = *src++);
//	NULL;
//	return ret;
//}

int main()
{
	char arr[10];
	my_strcpy(arr,"hello");
	printf("%s\n",arr);
	system("pause");
	return 0;
}