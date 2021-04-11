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
	ElemType c;
	sqstack s;
	int len,i,sum=0;
	initialstack(&s);
	printf("请输入二进制数，输入#表示结束\n");
	scanf("%c",&c);
	while(c!='#')
	{
		Push(&s,c);
		scanf("%c",&c);
	}
	getchar();//把空格键给拿出来
	len=Stacklen(s); 
	printf("当前容量：%d\n",len);
	for(i=0;i<len;i++)
	{
		Pop(&s,&c);
		sum=sum+(c-48)*pow(2,i);//取出来的C是ASCII码，减48后知道是1还是0 //48-57=0-9
	}
	printf("转换为十进制数%d\n",sum);

	return 0;
}








