#include<stdio.h>

int main()
{
	int sum=0;
	int i,j;
	
	do{
	sum+=i;
	printf("请输入合法的数字\n");
	j=scanf("%d",&i);
	}while(j==1);
	printf("和为；%d",sum);
 
 
 	return 0;
 } 
