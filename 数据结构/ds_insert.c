#include<stdio.h>
#include<stdlib.h> 
/*����洢�ṹ�Ķ���*/
typedef struct CLinkList
{
    int data;
    struct CLinkList *next;
}node;

/*������*/
/*����������ĵ�һ����㣬�����λ��*/
void initial(node **L)
{
	int i;
	node *p,*q;
	*L=(node *)malloc(sizeof(node));
	if(!*L)
	{
		exit(0);
	}
	(*L)->next=NULL;
	for(i=1;i<10;i++)
	{
		q=(node *)malloc(sizeof(node));
		q->data=i;
		q->next=(*L)->next;
		(*L)->next=q;
	}
}
void ds_insert(node **pNode , int i)
{
    node *temp;
    node *target;
    node *p;
    int item;
    int j = 1;

    printf("����Ҫ�������ֵ:");
    scanf("%d", &item);

    if(i == 1)
	{ //�²���Ľ����Ϊ��һ�����
        temp = (node *)malloc(sizeof(struct CLinkList));

		if(!temp)
            exit(0);

		temp->data = item;

        /*Ѱ�ҵ����һ�����*/
        for(target = (*pNode); target->next != (*pNode); target = target->next)
			;

		temp->next = (*pNode);
        target->next = temp;
        *pNode = temp;
    }
    else
	{
        target = *pNode;

		for( ; j < (i-1); ++j )
		{
			target = target->next;
		}  
		
		// targetָ�������Ԫ�ص�
		
		temp = (node *)malloc(sizeof(struct CLinkList));

		if(!temp)
            exit(0);

		temp->data = item;
		
        p = target->next;
        target->next = temp;
        temp->next = p;
    }
}

int main()
{
	int i,j;
	node *L;
	initial(&L);
	printf("������Ҫ����Ľڵ�λ��");
	scanf("%d",&i);
	ds_insert(&L ,i);
	for(i=0;i<11;i++)
	{
		L=L->next;
		printf("%d ",L->data);
	}
	return 0;
}
