#include<stdio.h>
#include<stdlib.h>
typedef struct CELL{
	int data; 
	struct CELL *next;
}CELL; 
CELL *CELL_alloc(int data)
{
	CELL *p=malloc(sizeof(CELL));
	p->data=data;
	p->next=NULL; return p;
 } 
void insert2(CELL **head_p,int data)
{
	CELL *new=CELL_alloc(data);
	CELL **p=head_p;
	while((*p)!=NULL&&data>(*p)->data){
		p=&(*p)->next;
	}
	new->next=*p;
	*p=new;	
 } 
int main()
{
	int i=0;
	CELL *head=NULL;
	insert2(&head,10);
	insert2(&head,30);
	insert2(&head,20);
	insert2(&head,15);
	CELL *p=head;
	for(i=0;i<4;i++){
		printf("%d ",p->data);
		p=p->next;
	}
	return 0;
}








