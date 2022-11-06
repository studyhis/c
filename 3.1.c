#include<stdio.h>
//你的体重等于白金
int main()
{
	float weight;//声明体重
	float value;//声明相等重量的白金价格

	printf("Are you worth your weight in platinum?\n");
	printf("Let's check it out.\n");
	printf("Please enter your weight in pounds:\n");

	//输入体重
	scanf_s("%f", &weight);//读取键盘的输入
	
	//假设白金的价格是每盎司$1700,14.5833用于把英镑常衡盎司转化为金衡盎司
	value = 1700.0 * weight * 14.5833;

	//你体重的白金值是;%.2f中的.2用于精确控制输出，指定输出浮点数只显示小数点的后面两位
	printf("Your weight in platinum is worth $%.2f.\n",value);
	return 0;
}
//金属盎司用于衡量贵金属，而英镑常衡盎司用于衡量人的体重
//变量：weight,value;  常量：1700.0,14.5833
