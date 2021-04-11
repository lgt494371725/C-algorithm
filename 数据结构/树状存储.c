#define MAX_TREE_SIZE 100
typedef ElemType char
typedef struct  PTnode
{
	ElemType data;
	int father;
	int chlid1;
	int child2;
}PTnode;
typedef struct Ptree
{
	int r;
	int n;
	PTnode nodes[NAX_TREE_SIZE];
}Ptree;

typedef struct Child
{
	int chlid;
	struct CTNode *next;
}*ChildPtr;
typedef struct  PTnode
{
	ElemType data;
	int father;
	ChildPtr firstchild;
}PTnode

typedef struct Ptree
{
	int r;
	int n;
	PTnode nodes[NAX_TREE_SIZE];
}Ptree;
