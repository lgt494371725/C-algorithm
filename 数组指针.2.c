#include<stdio.h>
int main()
{
	int a[2][3]={0,1,2,3,4,5};
	int (*p)[3]=a;
	printf("%d",*(p+0)+1);

}
