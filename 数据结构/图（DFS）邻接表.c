

#define TRUE 1
#define FALSE 0
#define MAX 256

typedef int Boolean; // TRUE表示已访问，FALSE表示还未访问 
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
		visited[i] = FALSE;	// 初始化数组，都未访问过 
	}
	
	for( i=0; i < GL->numVertexes; i++ )
	{
		if( !visited[i] )		// 若未被访问过，则开始遍历 
		{
			DFS(GL, i);
		}
	}
}
