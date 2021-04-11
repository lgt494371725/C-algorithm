#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr1=NULL;
	int *ptr2=NULL;
	ptr1=(int*)malloc(sizeof(int));
	ptr2=(int *)malloc(sizeof(int));
	printf("stack=%p-->%p\n",&ptr1,&ptr2);//栈从高向低 
	printf("heap:%p-->%p\n",ptr1,ptr2);//堆从低到高  
	return 0;
}
