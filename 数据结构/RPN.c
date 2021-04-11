


//该程序不完整，缺少push数字的部分 
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
	*(s->top)=e;//推入值，解引用 
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
int Stacklen(sqstack s)//因为不需要修改栈，可以不传指针 
{
	return(s.top-s.base);//不是地址的相减，而是元素的差 
}
int main()
{
	sqstack s;
	char c;
	char str[100];
	int i=0; 
	double d,e;
	printf("请按逆波兰表达式输入数据，数据与运算符间用空格隔开，以#作为结束标志\n");
	initialstack(&s);
	scanf("%c",&c);
	while(c!='#')
	{
		while(isdigit(c)||c=='.')//判断c是否是数字，用于过滤数字 
		{
			str[i++]=c;
			str[i]='\0';
			if(i>=10)
			{
				printf("出错：输入的单个数据过大!\n");
				return -1; 
			}
			scanf("%c",&c);//缓冲区！！每次scanf消耗一个缓冲区的字符 
			
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
				if(e!=0)//很重要！细节判断除数是否为0 
				{
				Push(&s,d/e);
				}
				else
				{printf("出错，除数不能为0"); 
					return -1;
				}break; 	
		}
		scanf("%c",&c);
	}
	Pop(&s,&d);
	printf("\n最终计算结果为：%f\n",d);

	return 0;
}









