#include<stdio.h>
//��ʾ�ַ�������
int main()
{
	char ch;

	printf("Please enter a character.\n");
	scanf_s("%c", &ch);                       //�û������ַ�
	printf("The code for %c is %d.\n",ch,ch);

	return 0;
}//��%cָ����ӡ�ַ�