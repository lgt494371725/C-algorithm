#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define STACKSIZE 20
#define increament 10
typedef char ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}sqstack;
void initialstack(sqstack *s)
{
	s->base=(ElemType *)malloc(STACKSIZE*sizeof(ElemType));
	if(!s->base)
	{
		exit(0);
	}
	s->top=s->base;
	s->stacksize=STACKSIZE;
}
void Push(sqstack*s,ElemType e)
{
	if(s->top-s->base>=s->stacksize)
	{
		s->base=(ElemType *)realloc(s->base,(s->stacksize+increament)*sizeof(ElemType));
	}
	if(!s->base)
	{
		exit(0);
	}
	*(s->top)=e;//����ֵ�������� 
	s->top++;
}
void Pop(sqstack *s,ElemType *e)
{
	if(s->top==s->base)
	{
		return ;
	}
	*e=*--(s->top);	
}
int Stacklen(sqstack s)//��Ϊ����Ҫ�޸�ջ�����Բ���ָ�� 
{
	return(s.top-s.base);//���ǵ�ַ�����������Ԫ�صĲ� 
}
int main()
{
	ElemType c;
	sqstack s;
	int len,i,sum=0;
	initialstack(&s);
	printf("�������������������#��ʾ����\n");
	scanf("%c",&c);
	while(c!='#')
	{
		Push(&s,c);
		scanf("%c",&c);
	}
	getchar();//�ѿո�����ó���
	len=Stacklen(s); 
	printf("��ǰ������%d\n",len);
	for(i=0;i<len;i++)
	{
		Pop(&s,&c);
		sum=sum+(c-48)*pow(2,i);//ȡ������C��ASCII�룬��48��֪����1����0 //48-57=0-9
	}
	printf("ת��Ϊʮ������%d\n",sum);

	return 0;
}








