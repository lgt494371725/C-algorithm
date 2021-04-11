#include<stdio.h>
int main()
{
	int k=0;
	int i=0,j=0;
	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int *p[3];
	for(k;k<3;k++)
	{
	p[k]=a[k];
		for(j=0;j<4;j++)
		{
			printf("%d ",p[k][j]);
		}
	printf("\n");
	}




	return 0;
}
