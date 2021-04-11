

#define TRUE 1
#define FALSE 0
#define MAX 256

typedef int Boolean; // TRUE��ʾ�ѷ��ʣ�FALSE��ʾ��δ���� 
Boolean visited[MAX];

void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
	
	visited[i] = TRUE;
	printf("%c " GL->adjList[i].data);
	p = GL->adjList[i].firstEdge;
	
	while(p)
	{
		if( !visited[p->adjvex] )
		{
			DFS(GL, p->adjvex);
		}
		p = p->next;
	}
}


void DFSTraverse(GraphAdjList GL)
{
	int i;
	
	for( i=0; i < GL->numVertexes; i++ )
	{
		visited[i] = FALSE;	// ��ʼ�����飬��δ���ʹ� 
	}
	
	for( i=0; i < GL->numVertexes; i++ )
	{
		if( !visited[i] )		// ��δ�����ʹ�����ʼ���� 
		{
			DFS(GL, i);
		}
	}
}
