#include<stdio.h>

int main()
{
	char israin,isfree;
	printf("�Ƿ��пգ�Y/N��");
	scanf("%c",&isfree);
	
	getchar();
	
	printf("�Ƿ����꣨Y/N��");
	scanf("%c",&israin);
	
	if(isfree=='Y')
	{	if(israin=='Y')
		printf("�ǵô�ɡ\n");
	}
	else
	{ 
		printf("Ů��û��");
	}	 
	return 0;
}
