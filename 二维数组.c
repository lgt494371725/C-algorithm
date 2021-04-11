#include<stdio.h>
int main()
{
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};//用大括号括起来更加直观 
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("%d",a[i][j]);
		putchar('\n');//也可以用printf（"\n"); 
	}
	return 0;
}

