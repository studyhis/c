#include<stdio.h>
int main()
{
	int x = 100;

	printf("dec=%d;octal=%o;hex=%x\n", x, x, x);  //100; 144; 64	(ʮ���ƣ��˽��ƣ�ʮ������)
	printf("dec=%d;octal=%#o;hex=%#x\n", x, x, x);//100;0144;0x64	(ʮ���ƣ��˽��ƣ�ʮ������)
	
	return 0;
}
//�ڰ˽��ƺ�ʮ������ֵǰ��ʾ0��0xǰ׺��Ҫ�ֱ���ת��˵���м���#