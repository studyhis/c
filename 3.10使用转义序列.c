#include<stdio.h>

int main()
{
	float salary;

	printf("\aEnter your desired monthly salary: ");//  \a-¾¯±¨Éù
	printf(" $_________\b\b\b\b\b\b\b");//  \b-ÍË¸ñ
	scanf_s("%f", &salary);
	printf("\n\t$%.2f a month is $%.2f a year.", salary,salary*12.0);//  \t-Ë®Æ½ÖÆ±í·û

	printf("\tGee!\n");

	return 0;
}
