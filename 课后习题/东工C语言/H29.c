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
CELL *insert1(CELL *head,int data){
	CELL *new=CELL_alloc(data);
	CELL *p=head;
	if(p==NULL||data<p->data){
		new->next=p;
		return new;
	}else{
		while(p->next!=NULL&&data>p->next->data){
			p=p->next;
		}
		new->next=p->next;p->next=new;
		return head;
	}
}
int main()
{
	int i=0;
	CELL *head=NULL;
	head=insert1(head,10);
	head=insert1(head,30);
	head=insert1(head,20);
	CELL *p=head;
	for(i=0;i<3;i++){
		printf("%d ",p->data);
		p=p->next;
	}
	return 0;
}








