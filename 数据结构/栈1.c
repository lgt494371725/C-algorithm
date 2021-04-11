#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
	int *base;
	int top;
	int a;
}stack;

int main()
{
	int *b;
	int num=120;
	b=&num;
	stack *p;
	p=(stack *)malloc(100);
	p->a=5;
	printf("%p",b);

	return 0;
}



 
