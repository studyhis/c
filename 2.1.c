#include<stdio.h>//预处理器指令
int main()
{
	int num;//定义一个整型变量
	num = 1;//为num赋值(赋值表达式语句)

	printf("I am a simple ");//使用printf()函数-----格式化打印函数
	printf("computer.\n");//computer是printf()函数的实际参数
	printf("My favorite number is %d because it is first.\n", num);// \n是换行

	return 0;
}
/*
\t代表Tab键
\b代表Backspace键
\是反斜杠字符
*/