#include<stdio.h>

int main()
{
	int sum=0;
	int i,j;
	
	do{
	sum+=i;
	printf("������Ϸ�������\n");
	j=scanf("%d",&i);
	}while(j==1);
	printf("��Ϊ��%d",sum);
 
 
 	return 0;
 } 
