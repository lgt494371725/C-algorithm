#include<stdio.h>

int main()
{
	char name[100];
	float height,weight;
	printf("��������������");
	scanf("%s",name);//�ַ�������Ҫ�ӵ�ַ�� 
	printf("�������������");
	scanf("%f",&height);
	printf("��������������");
	scanf("%f",&weight);
	printf("����Ϊ��ת��");
	height=height/2.54;
	weight=weight/0.453;
	printf("%s������ǣ�%.2fӢ��,����������%.2f��",name,height,weight);
	return 0;
 } 
