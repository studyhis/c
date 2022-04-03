//#include<stdio.h>
//void bc();
//void vc();
//int main()
//{
//	bc();
//	bc();
//	vc();
//	printf("!\n");
//	bc(), vc();
//	printf("!\n");
//	bc();
//	return 0;
//}
//
//void bc()
//{
//	printf("Smile!");
//}
//
//void vc()
//{
//	printf("Smile");
//}

#include<stdio.h>
void Smile();//调用一个函数
int main()
{
	Smile();
	Smile();
	Smile();
	printf("\n");
	Smile();
	Smile();
	printf("\n");
	Smile();

	return 0;
}
void Smile()
{
	printf("Smile!");
}