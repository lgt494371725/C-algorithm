#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr1=NULL;
	int *ptr2=NULL;
	ptr1=(int*)malloc(sizeof(int));
	ptr2=(int *)malloc(sizeof(int));
	printf("stack=%p-->%p\n",&ptr1,&ptr2);//ջ�Ӹ���� 
	printf("heap:%p-->%p\n",ptr1,ptr2);//�Ѵӵ͵���  
	return 0;
}
