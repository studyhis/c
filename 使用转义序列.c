#include<stdio.h>

int main()
{
	float salary;

	printf("\aEnter your desired monthly salary: ");//  \a-������
	printf(" $_________\b\b\b\b\b\b\b");//  \b-�˸�
	scanf_s("%f", &salary);
	printf("\n\t$%.2f a month is $%.2f a year.", salary,salary*12.0);//  \t-ˮƽ�Ʊ��

	printf("\tGee!\n");

	return 0;
}