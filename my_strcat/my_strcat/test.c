#include <stdio.h>
#include <Windows.h>
#include <assert.h>


char* my_strcat(char* dest,const char* src)
{
    char *ret = dest;

	assert(dest);
	assert(src);
	
	while(*dest)
		dest++;        //�ҵ�Ŀ�괮\0��λ��

	while(*dest++ = *src++)
		;                 //��Ŀ�괮\0��λ�ÿ�ʼ��src�Ž�ȥ

	return ret;
}

int main()
{
	char arr[20] = "qqqqqq";    //����Ĵ�С�����㹻
	my_strcat(arr,"abcdef");
	printf("%s\n",arr);
	system("pause");
	return 0;
}