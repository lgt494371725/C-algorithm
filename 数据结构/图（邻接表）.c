图，邻接表
#deinfe MAXVEXS 100

typedef struct Edgenode
{
	int weight;
	int adjvex;
	struct Edgenode *next;
}Edgenode;

typedef struct vexnode
{
	char data;
	Edgenode *firstedge;
}vexnode,Adlist[MAXVEXS];
typedef struct graph
{
	Adlist adlist;
	int numvexs;
	int numedges;
}Graphadlist;
void CreateAdlist(Graphadlist *G)
{
	int i,i,k,w;
	Edgenode *e;
	printf("请输入顶点数和边数",&G->numedges,&G->numvexs);
	for(i=0;i<G->numvexs,i++)
	{
		scanf("%c",&G->adlist[i].data);//录入顶点信息 
		G->adlist[i].firstedge=NULL;//初始化指针 
	}
	for(k=0;k<G->numedges;k++)
	{
		printf("请输入边的关联点及权");
		scanf("%d %d %d",&i,&j,&w);
		e=(Edgenode *)malloc(sizeof(Edgenode));
		e->adjvex=j;
		e->next=G->adlist[i].firstedge;//出度 ，头插法 
		G->adlist[i].firstedge=e; 
	
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = i;						//入度，与出度二选一进行创建 
		e->next = G->adjList[j].firstEdge;
		G->adjList[j].firstEdge = e;
	
	}
}









