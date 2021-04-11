#include<stdio.h>
#include<stdlib.h>//malloc”√ 
#define N 10
#include<string.h>//mem”√ 
int main(void)
{
	int *ptr=NULL;
	int i;
	ptr=(int *)malloc(N*sizeof(int));
	memset(ptr,0,N*sizeof(int));// 
	for(i=0;i<N;i++)
	{
		printf("%d ",ptr[i]);
	}
	return 0;
}
