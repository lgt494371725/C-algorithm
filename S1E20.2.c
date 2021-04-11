#include<stdio.h>
int main()
{
	int a[2][3]={1,2,3,4,5,6};
	int b[3][2]={1,4,2,5,3,6};
	int c[2][2]={0};
	int i,j,k,row;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			for(k=0;k<3;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
			
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
	{
			printf("%d ",c[i][j]);
		
	}
		putchar('\n');
	}
	
	
	return 0;
}
