#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct BiNode
{
	ElemType data;
	struct BiNode *lchild,*rchild;	
}BiNode,*BiTree;
visit(BiTree T,int level)
{
	printf("%c--%d\n",T->data,level);
}
CreateBiTree(BiTree *T)
{
	ElemType c;
	scanf("%c",&c);
	if(' '==c)
	{
		*T=NULL;
	}
	else
	{
		*T=(BiNode *)malloc(sizeof(BiNode));
		(*T)->data=c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}

}
PreOrder(BiTree T,int level)
{
	if(T)
	{
		visit(T,level);
		PreOrder(T->lchild,level+1);
		PreOrder(T->rchild,level+1);		
	}
}

int main()
{
	int level=1;
	BiTree T=NULL;
	printf("请按前序遍历输入");
	CreateBiTree(&T);
	PreOrder(T,level);

	return 0;
}















