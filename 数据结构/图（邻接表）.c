ͼ���ڽӱ�
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
	printf("�����붥�����ͱ���",&G->numedges,&G->numvexs);
	for(i=0;i<G->numvexs,i++)
	{
		scanf("%c",&G->adlist[i].data);//¼�붥����Ϣ 
		G->adlist[i].firstedge=NULL;//��ʼ��ָ�� 
	}
	for(k=0;k<G->numedges;k++)
	{
		printf("������ߵĹ����㼰Ȩ");
		scanf("%d %d %d",&i,&j,&w);
		e=(Edgenode *)malloc(sizeof(Edgenode));
		e->adjvex=j;
		e->next=G->adlist[i].firstedge;//���� ��ͷ�巨 
		G->adlist[i].firstedge=e; 
	
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->adjvex = i;						//��ȣ�����ȶ�ѡһ���д��� 
		e->next = G->adjList[j].firstEdge;
		G->adjList[j].firstEdge = e;
	
	}
}









