#include<stdio.h>
int main()
{
	int x = 100;

	printf("dec=%d;octal=%o;hex=%x\n", x, x, x);  //100; 144; 64	(十进制，八进制，十六进制)
	printf("dec=%d;octal=%#o;hex=%#x\n", x, x, x);//100;0144;0x64	(十进制，八进制，十六进制)
	
	return 0;
}
//在八进制和十六进制值前显示0和0x前缀，要分别在转换说明中加入#