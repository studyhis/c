#include<stdio.h>
//一个文件包含两个函数

void butler();//函数原型（函数声明）
int main()
{
	printf("Hello,I am Terry.\n");
	butler();//函数调用

	return 0;
}
void butler()//函数定义
{
	printf("Hey,I am Yadang.\n");
}
