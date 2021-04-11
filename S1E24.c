#include<stdio.h>
int main()
{
	int i,j;
	char ch[3][3]={0};
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			ch[i][j]=getchar();
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%c ",ch[i][j]);	
		}
		printf("\n");
	}
	

	return 0;
 } 
