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
	s=(sqstack *)malloc(100);//�ڸ�base����ռ�֮ǰҪ�ȸ��ṹ������ռ� 
	s->base=(int *)malloc(100);
	s->top=s->base;
	printf("%p",s->base-s->top);
	
	return 0;
}
