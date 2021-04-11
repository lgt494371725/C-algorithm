#include<stdio.h>

int sum(int n);
int sum(int n)//不要；符号 ,括号里的int去掉结果不变 
{
	int result=0;
	do
	{
	result+=n;
	}while(n-->0);
	return 0;
}
int main()
{
	int n,result;
	printf("请输入n的值：");
	scanf("%d",&n);
	result=sum(n);
	printf("1+2+3+xxx+n的结果是：%d\n",result);
	return 0;	
}
