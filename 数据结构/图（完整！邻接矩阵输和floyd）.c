#define MAXVEX 100
#define INFINITY	65535
#include<stdio.h>


typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];
typedef struct
{
	char vexs[MAXVEX];//��
	int edge[MAXVEX][MAXVEX];//�� 
	int numvexs,numedge;//��¼����ͱߵĸ��� 
}Graph; 

void CreateGraph(Graph *G)
{
	int i,j,k,w;
 
 	printf("��ֱ����붥��ͱߵĸ���\n");
	scanf("%d %d",&G->numvexs,&G->numedge);//ֱ�����룬û��Ҫ���ñ��� 
	getchar();
	for(i=0;i<G->numvexs;i++)
	{
		printf("�����\n");
		scanf("%c",&G->vexs[i]); 
		getchar();
	}
	for(i=0;i<G->numvexs;i++)//�ǵ����Ƚ������ʼ������ 
	{
		for(j=0;j<G->numvexs;j++)
		{
			G->edge[i][j]=0;
		}
	}
	for(k=0;k<G->numedge;k++)
	{
		printf("����ߵĹ����㼰Ȩ\n");
		scanf("%d %d %d",&i,&j,&w);
		getchar();
		G->edge[i][j]=w;
		G->edge[j][i]=G->edge[i][j];//�Գƾ��� 
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
	
	// ��ʼ��D��P 
	for( v=0; v < G.numvexs; v++ )
	{
		for( w=0; w < G.numvexs; w++ )
		{
			(*D)[v][w] = G.edge[v][w];//D������Ȩֵ����D[1][3]��ʾ����1������3����СȨֵ 
			(*P)[v][w] = w;//p�����ʾ������������㣬��ʾ����i������j������p[i][j]����ʾ�Ķ��㣬��v1��v4=3����ʾ1��4���뾭��3������� 
		}//p�����ȳ�ʼ��Ϊ����㼴0123456.�� 
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
					(*P)[v][w] = (*P)[v][k];	//Ҫ�����仰��Ϊʲô���ǰ�k��ֵ��ȥ�����ɣ���Ϊ�����1��5Ҫ����3������ֱ�Ӹ�ֵ3 
				}									//��Ϊ1��3һ��Ҫ����2��Ӧ�ø�ֵ����ģ���1��5һ��Ҫ����2��Ȼ��2��5һ��Ҫ����3����������˳���� 
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




