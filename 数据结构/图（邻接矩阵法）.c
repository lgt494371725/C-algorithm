�ڽӾ���,������Ȩͼ 

#define MAXVEX 100
 
typedef struct
{
	char vexs[MAXVEX]//��
	int edge[MAXVEX][MAXVES]//�� 
	int numvexs,numedge//��¼����ͱߵĸ��� 
}Graph; 

void CreateGraph(Graph *G)
{
	int i,j,k,w;
	char 
	printf("��ֱ����붥��ͱߵĸ���");
	scanf("%d %d",&G->numvex,&G->numedge);//ֱ�����룬û��Ҫ���ñ��� 
	for(i=0;i<G->numvex;i++)
	{
		scanf("%c",&G->vexs[i]); 
	}
	for(i=0;i<G->numvexs;i++)//�ǵ����Ƚ������ʼ������ 
	{
		for(j=0;j<G->numves;j++)
		{
			G->edge[i][j]=0;
		}
	}
	for(k=0;k<G->numedge;k++)
	{
		printf("����ߵĹ����㼰Ȩ");
		scanf("%d %d %d",&i,&j,&w);
		G->edge[i][j]=w;
		G->edge[j][i]=G->edge[i][j];//�Գƾ��� 
	}
}
