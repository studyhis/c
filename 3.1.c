#include<stdio.h>
//������ص��ڰ׽�
int main()
{
	float weight;//��������
	float value;//������������İ׽�۸�

	printf("Are you worth your weight in platinum?\n");
	printf("Let's check it out.\n");
	printf("Please enter your weight in pounds:\n");

	//��������
	scanf_s("%f", &weight);//��ȡ���̵�����
	
	//����׽�ļ۸���ÿ��˾$1700,14.5833���ڰ�Ӣ�����ⰻ˾ת��Ϊ��ⰻ˾
	value = 1700.0 * weight * 14.5833;

	//�����صİ׽�ֵ��;%.2f�е�.2���ھ�ȷ���������ָ�����������ֻ��ʾС����ĺ�����λ
	printf("Your weight in platinum is worth $%.2f.\n",value);
	return 0;
}
//������˾���ں������������Ӣ�����ⰻ˾���ں����˵�����
//������weight,value;  ������1700.0,14.5833
