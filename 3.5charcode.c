#include<stdio.h>
//显示字符代码编号
int main()
{
	char ch;

	printf("Please enter a character.\n");
	scanf_s("%c", &ch);                       //用户输入字符
	printf("The code for %c is %d.\n",ch,ch);

	return 0;
}//用%c指待打印字符