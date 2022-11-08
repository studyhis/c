#include<stdio.h>
#include<inttypes.h>//支持可移植类型

int main()
{
	int32_t me32;//me32是一个32位有符号整型变量

	me32 = 45933945;
	printf("First,assume int32_t is int: ");//assume-假设
	printf("me32 = %d\n", me32);
	printf("Next, let's not make any assumptions.\n ");//assumptions-设想
	printf("Instead,use a \"macro\" from inttypes.h: ");
	printf("me32 = %" PRId32 "\n", me32);
	//printf("me32 = %d\n", me32);
	return 0;
}