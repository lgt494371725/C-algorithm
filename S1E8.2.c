#include<stdio.h>

int main()
{
	char name[100];
	float height,weight;
	printf("请输入您的姓名");
	scanf("%s",name);//字符串不需要加地址符 
	printf("请输入您的身高");
	scanf("%f",&height);
	printf("请输入您的体重");
	scanf("%f",&weight);
	printf("正在为您转换");
	height=height/2.54;
	weight=weight/0.453;
	printf("%s的身高是：%.2f英寸,您的体重是%.2f磅",name,height,weight);
	return 0;
 } 
