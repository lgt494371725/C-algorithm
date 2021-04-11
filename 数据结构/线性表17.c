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
		p=q;//ʹ�������� 
	}
	q->next=(*L)->next;//ͷ��㲻����ѭ������Ϊͷ�ڵ�û�����ݣ����������Ҫ���нڵ�����ݹ��� 
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
		(*L)=(*L)->next->prior;//��һ���ܹؼ�!!!û����һ�л�ִ��ʧ�ܣ���ʼ��*L��û��prior 
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
	printf("������һ������");
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
