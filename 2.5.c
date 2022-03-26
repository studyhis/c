#include<stdio.h>
void br();//调用函数
void ic();//调用函数
int main()
{
	br();
	printf(",");
	ic();
	printf("\n");
	ic();
	printf("\n");
	br();

	return 0;
}

void br()
{
	printf("Brazil,Russia");
}
void ic()
{
	printf("India,China\n");
}

