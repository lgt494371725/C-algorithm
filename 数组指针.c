
#include<stdio.h>

int main()
{
	int a[5]={1,2,3,4,5};
	int (*p2)[5]=&a;//*p2=a
	int i;
	for (i=0;i<5;i++)
	{
		printf("%d\n",*(*p2+i));//*p£¨2+1£© 
	}
	

	return 0;
}
