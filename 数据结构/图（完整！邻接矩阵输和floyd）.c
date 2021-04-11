#define MAXVEX 100
#define INFINITY	65535
#include<stdio.h>


typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];
typedef struct
{
	char vexs[MAXVEX];//顶
	int edge[MAXVEX][MAXVEX];//边 
	int numvexs,numedge;//记录顶点和边的个数 
}Graph; 

void CreateGraph(Graph *G)
{
	int i,j,k,w;
 
 	printf("请分别输入顶点和边的个数\n");
	scanf("%d %d",&G->numvexs,&G->numedge);//直接输入，没必要多用变量 
	getchar();
	for(i=0;i<G->numvexs;i++)
	{
		printf("输入点\n");
		scanf("%c",&G->vexs[i]); 
		getchar();
	}
	for(i=0;i<G->numvexs;i++)//记得首先将矩阵初始化！！ 
	{
		for(j=0;j<G->numvexs;j++)
		{
			G->edge[i][j]=0;
		}
	}
	for(k=0;k<G->numedge;k++)
	{
		printf("输入边的关联点及权\n");
		scanf("%d %d %d",&i,&j,&w);
		getchar();
		G->edge[i][j]=w;
		G->edge[j][i]=G->edge[i][j];//对称矩阵 
	}
	for( i=0; i < G->numvexs; i++ )
	{
		for( j=0; j < G->numvexs; j++ )
		{
		printf("%2d ",G->edge[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void ShortestPath_Floyd(Graph G, Pathmatirx *P, ShortPathTable *D)
{
	int v, w, k;
	
	// 初始化D和P 
	for( v=0; v < G.numvexs; v++ )
	{
		for( w=0; w < G.numvexs; w++ )
		{
			(*D)[v][w] = G.edge[v][w];//D矩阵存放权值，如D[1][3]表示顶点1到顶点3的最小权值 
			(*P)[v][w] = w;//p矩阵表示经过了这个顶点，表示顶点i到顶点j经过了p[i][j]所表示的顶点，如v1，v4=3，表示1到4必须经过3这个顶点 
		}//p矩阵先初始化为自身点即0123456.。 
	}
	

	for( k=0; k < G.numvexs; k++ )
	{
		for( v=0; v < G.numvexs; v++ )
		{
			for( w=0; w < G.numvexs; w++ )
			{
				if( (*D)[v][w] > (*D)[v][k] + (*D)[k][w] )
				{
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					(*P)[v][w] = (*P)[v][k];	//要理解这句话，为什么不是把k赋值过去的理由，因为比如从1到5要经过3，不能直接赋值3 
				}									//因为1到3一定要经过2，应该赋值最近的，故1到5一定要经过2，然后2到5一定要经过3，按这样的顺序来 
			}
		}
	}
	for( k=0; k < G.numvexs; k++ )
	{
		for( v=0; v < G.numvexs; v++ )
		{
		printf("%2d ",(*P)[k][v]);
		}
		printf("\n");
	}

}
int main() 
{
	Graph G;
	Pathmatirx P;
	ShortPathTable D;
	CreateGraph(&G);
	ShortestPath_Floyd(G, &P, &D);


	return 0;
}




