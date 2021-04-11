邻接矩阵法,创建带权图 

#define MAXVEX 100
 
typedef struct
{
	char vexs[MAXVEX]//顶
	int edge[MAXVEX][MAXVES]//边 
	int numvexs,numedge//记录顶点和边的个数 
}Graph; 

void CreateGraph(Graph *G)
{
	int i,j,k,w;
	char 
	printf("请分别输入顶点和边的个数");
	scanf("%d %d",&G->numvex,&G->numedge);//直接输入，没必要多用变量 
	for(i=0;i<G->numvex;i++)
	{
		scanf("%c",&G->vexs[i]); 
	}
	for(i=0;i<G->numvexs;i++)//记得首先将矩阵初始化！！ 
	{
		for(j=0;j<G->numves;j++)
		{
			G->edge[i][j]=0;
		}
	}
	for(k=0;k<G->numedge;k++)
	{
		printf("输入边的关联点及权");
		scanf("%d %d %d",&i,&j,&w);
		G->edge[i][j]=w;
		G->edge[j][i]=G->edge[i][j];//对称矩阵 
	}
}
