#pragma once
#include<ctype.h>

char* Replace(char str[],int length)
{
	//ʵ�ʳ��ȺͿո���
	int originlength = 0;
	int blanklength = 0;
	int i = 0;
	while (str[i] != 0)
		;

}

 /*length Ϊ�ַ�����string��������*/
//void ReplaceBlank(char string[], int length)
//{
//	if (string == NULL && length <= 0)
//	        return;
//	
//	     /*originalLength Ϊ�ַ���string��ʵ�ʳ���*/
//	     int originalLength = 0;
//	 int numberOfBlank = 0;
//	 int i = 0;
//	 while (string[i] != '\0')
//	 {
//	     ++originalLength;
//	
//	         if (string[i] == ' ')
//	             ++numberOfBlank;
//	
//	         ++i;
//	 }
//	
//	 /*newLength Ϊ�ѿո��滻��'%20'֮��ĳ���*/
//	 int newLength = originalLength + numberOfBlank * 2;
//	if (newLength > length)
//	        return;
//	
//	    int indexOfOriginal = originalLength;
//	int indexOfNew = newLength;
//	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
//	    {
//	        if (string[indexOfOriginal] == ' ')
//	         {
//	             string[indexOfNew--] = '0';
//	             string[indexOfNew--] = '2';
//	             string[indexOfNew--] = '%';
//	         }
//	      else
//	         {
//	             string[indexOfNew--] = string[indexOfOriginal];
//	         }
//	
//	         --indexOfOriginal;
//	    }
//	 }
//}*/