#include<stdio.h>

int main()
{
	char israin,isfree;
	printf("是否有空（Y/N）");
	scanf("%c",&isfree);
	
	getchar();
	
	printf("是否下雨（Y/N）");
	scanf("%c",&israin);
	
	if(isfree=='Y')
	{	if(israin=='Y')
		printf("记得带伞\n");
	}
	else
	{ 
		printf("女神没空");
	}	 
	return 0;
}
