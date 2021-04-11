#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
// Link(0)表示指向左右孩子的指针 
// Thread(1)：前驱后继的线索 
typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode
{
	char data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag;
	PointerTag rtag;
} BiThrNode, *BiThrTree;


BiThrTree pre;//全局变量 


void CreateBiThrTree( BiThrTree *T )
{
	char c;

	scanf("%c", &c);
	if( ' ' == c )
	{
		*T = NULL;
	}
	else
	{
		*T = (BiThrNode *)malloc(sizeof(BiThrNode));
		(*T)->data = c;//前序遍历 
		(*T)->ltag = Link;//默认有指针 
		(*T)->rtag = Link;

		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}

//中序遍历 
void InThreading(BiThrTree T)
{
	if( T )
	{
		InThreading( T->lchild );		// 递归左孩子 

		if( !T->lchild )	// 没左孩子，记录前驱节点 
		{
			T->ltag = Thread;
			T->lchild = pre;
		}

		if( !pre->rchild )
		{
			pre->rtag = Thread;
			pre->rchild = T;
		}

		pre = T;

		InThreading( T->rchild );		// 递归右孩子 
	}
}

void InOrderThreading( BiThrTree *p, BiThrTree T )
{
	*p = (BiThrTree)malloc(sizeof(BiThrNode));
	(*p)->ltag = Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;
	if( !T )
	{
		(*p)->lchild = *p;
	}
	else
	{
		(*p)->lchild = T;
		pre = *p;
		InThreading(T);
		pre->rchild = *p;
		pre->rtag = Thread;
		(*p)->rchild = pre;
	}
}

void visit( char c )
{
	printf("%c", c);
}

// 迭代法遍历二叉树  
void InOrderTraverse( BiThrTree T )
{
	BiThrTree p;
	p = T->lchild;

	while( p != T )
	{
		while( p->ltag == Link )
		{
			p = p->lchild;
		}
		visit(p->data);

		while( p->rtag == Thread && p->rchild != T )
		{
			p = p->rchild;
			visit(p->data);
		}
		
		p = p->rchild;
	}
}

int main()
{
	BiThrTree P, T = NULL;

	CreateBiThrTree( &T );

	InOrderThreading( &P, T );

	printf("中序遍历输出结果为： ");

	InOrderTraverse( P );

	printf("\n");

	return 0;
}
