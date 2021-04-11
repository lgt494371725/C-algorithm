#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define error 0
typedef char ElemType;
typedef int Status;
typedef struct DualNode
{
	ElemType data;
	struct DualNode *prior;
	struct DualNode *next;
	
 }DualNode,*DuLinkList;
 Status Initialist(DuLinkList *L)
 {
 	DualNode *p,*q;
 	int i;
 	*L=(DuLinkList)malloc(sizeof(DualNode));
 	if(!*L)
 	{
 		return error;	
	}
	(*L)->next=(*L)->prior=NULL;
	p=(*L);
	for(i=0;i<26;i++)
	{
		q=(DualNode*)malloc(sizeof(DualNode));
		if(!q)
		{
			return error;
		}
		q->data='A'+i;
		q->prior=p;
		q->next=p->next;
		p->next=q;
		p=q;//使链表动起来 
	}
	q->next=(*L)->next;//头结点不放入循环，因为头节点没有数据，这个程序需要让有节点的数据滚动 
 	(*L)->next->prior=q;
 	return OK;
 }
 void Caesar(DuLinkList *L,int i)
 {
 	if(i>0)
 	{
 		do{
 			(*L)=(*L)->next;
		 }while(--i);
	}
	if(i<0)
	{
		(*L)=(*L)->next->prior;//这一步很关键!!!没有这一行会执行失败，初始（*L）没有prior 
		do{
			(*L)=(*L)->prior;
			printf("1");
		}while(++i);
	}
 }
 int main()
 {
	DuLinkList L;
	int i,n;
	Initialist(&L);
	printf("请输入一个整数");
	scanf("%d",&n);
	
	Caesar(&L,n);
	for(i=0;i<26;i++)
	{
		L=L->next;
		printf("%c",L->data);
	}
	printf("\n");
	 return 0;
 }
