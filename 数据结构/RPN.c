


//�ó���������ȱ��push���ֵĲ��� 
#include<stdio.h>
#include<ctype.h> 
#include<stdlib.h>

#define STACKSIZE 20
#define increament 10
typedef double ElemType;
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
	sqstack s;
	char c;
	char str[100];
	int i=0; 
	double d,e;
	printf("�밴�沨�����ʽ�������ݣ���������������ÿո��������#��Ϊ������־\n");
	initialstack(&s);
	scanf("%c",&c);
	while(c!='#')
	{
		while(isdigit(c)||c=='.')//�ж�c�Ƿ������֣����ڹ������� 
		{
			str[i++]=c;
			str[i]='\0';
			if(i>=10)
			{
				printf("��������ĵ������ݹ���!\n");
				return -1; 
			}
			scanf("%c",&c);//����������ÿ��scanf����һ�����������ַ� 
			
		}
		switch(c) 
		{
			case'+':
				Pop(&s,&e); 
				Pop(&s,&d); 
				Push(&s,e+d);
				break;
			case'-':
				Pop(&s,&e); 
				Pop(&s,&d); 
				Push(&s,d-e);
				break;
			case'*':
				Pop(&s,&e); 
				Pop(&s,&d); 
				Push(&s,d*e);
				break;
			case'/':
				Pop(&s,&e); 
				Pop(&s,&d); 
				if(e!=0)//����Ҫ��ϸ���жϳ����Ƿ�Ϊ0 
				{
				Push(&s,d/e);
				}
				else
				{printf("������������Ϊ0"); 
					return -1;
				}break; 	
		}
		scanf("%c",&c);
	}
	Pop(&s,&d);
	printf("\n���ռ�����Ϊ��%f\n",d);

	return 0;
}









