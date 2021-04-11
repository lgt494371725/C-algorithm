

#define TRUE 1
#define FALSE 0
#define MAX 256

typedef int Boolean;	// TRUE表示已访问，FALSE表示还未访问 
Boolean visited[MAX];	//该数组表示哪些顶点被访问过 
void DFS(MGraph G, int i)
{
	int j;
	
	visited[i] = TRUE;			//标记该定位，已经访问过 
	printf("%c ", G.vexs[i]);	// 输出该顶点信息 
	for( j=0; j < G.numVertexes; j++ )
	{
		if( G.arc[i][j]==1 && !visited[j] )//只有该顶点未访问过且与其他点有连接才会进入 
		{
			DFS(G, j);			// 递归遍历 
		}
	}
}

void DFSTraverse(MGraph G)
{
	int i;
	
	for( i=0; i < G.numVertexes; i++ )
	{
		visited[i] = FALSE;		// 初始化数组，都未访问过 
	}
	
	for( i=0; i < G.numVertexes; i++ )//避免有不连通的图出现的情况 
	{
		if( !visited[i] )		// 若未被访问过，则开始遍历 
		{
			DFS(G, i);
		}
	}
}
