#include<stdio.h>
#include<stdlib.h> 
/*链表存储结构的定义*/
typedef struct CLinkList
{
    int data;
    struct CLinkList *next;
}node;

/*插入结点*/
/*参数：链表的第一个结点，插入的位置*/
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

    printf("输入要插入结点的值:");
    scanf("%d", &item);

    if(i == 1)
	{ //新插入的结点作为第一个结点
        temp = (node *)malloc(sizeof(struct CLinkList));

		if(!temp)
            exit(0);

		temp->data = item;

        /*寻找到最后一个结点*/
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
		
		// target指向第三个元素的
		
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
	printf("请输入要插入的节点位置");
	scanf("%d",&i);
	ds_insert(&L ,i);
	for(i=0;i<11;i++)
	{
		L=L->next;
		printf("%d ",L->data);
	}
	return 0;
}
