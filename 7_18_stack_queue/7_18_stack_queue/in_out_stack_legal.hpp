#pragma once


#include<stack>

//��ջ���� s
//��ջ���� d
//1.s��d�ĳ��Ȳ���ȣ�false
//2.s�ĵ�һ��Ԫ�ؽ�ջ���ж�ջ��Ԫ�غͳ�ջ����ָ��ָ���Ԫ���Ƿ����
	//2.1 ��ȣ���ջ������dָ�������
	//2.2 ����� �����s��Ϊ�գ�������ջ��ֱ��ƥ��
	//2.3 ���s=="\0";false
//

bool Is_in_out_stack_legal(char* s, char* d)
{
	stack<char> sk;

	if (strlen(s) != strlen(d))
		return false;

	sk.push(*s++);

	while (*d != '\0')
	{
		while (sk.top() != *d && *s != '\0') 
			sk.push(*s++);

		if (sk.top() == *d++)
		{
			sk.pop();
			continue;
		}
		if (*s == '\0'&& sk.top() != *d)
			return false;
	}
	return true;
 }


void In_Out_Stack()
{
	char* s = "12345";
	char* d = "67890";
	if (Is_in_out_stack_legal(s, d))
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

}






