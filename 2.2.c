#include<stdio.h>
//进制转换---把2英寻转换成英尺
int main()
{
	//声明变量英尺，英寻
	int feet, fathoms;
	//2英寻
	fathoms = 2;
	//1英寻=6英尺
	feet = 6 * fathoms;
	//打印输出
	printf("There are %d feet in %d fathoms!\n", feet, fathoms);
	printf("Yes,I said %d feet!\n", feet);


	return 0;
}