#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int *base;
	int *top;
	int num;
}sqstack;

int main()
{
	sqstack *s;
	s=(sqstack *)malloc(100);//在给base申请空间之前要先给结构体申请空间 
	s->base=(int *)malloc(100);
	s->top=s->base;
	printf("%p",s->base-s->top);
	
	return 0;
}
