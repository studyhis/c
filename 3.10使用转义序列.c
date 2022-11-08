#include<stdio.h>

int main()
{
	float salary;

	printf("\aEnter your desired monthly salary: ");//  \a-警报声
	printf(" $_________\b\b\b\b\b\b\b");//  \b-退格
	scanf_s("%f", &salary);
	printf("\n\t$%.2f a month is $%.2f a year.", salary,salary*12.0);//  \t-水平制表符

	printf("\tGee!\n");

	return 0;
}
