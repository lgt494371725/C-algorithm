https://blog.csdn.net/swustzhaoxingda/article/details/84318570
#define MAXVEX	9
#define	INFINITY	65535

typedef	int	Patharc[MAXVEX];			// 存储最短路径下标 
typedef int	ShortPathTable[MAXVEX];		// 存储到各点最短路径的权值和 

void ShortestPath_Dijkstar(MGraph G, int V0, Patharc *P, ShortPathTable *D)
{
	int v, w, k, min;
	int final[MAXVEX];		// final[w] = 1 表示已经求得顶点v0到vw的最短路径 
	
	for( v=0; v < G.numVertexes; v++ )
	{
		final[v] = 0;				// 全部顶点初始化为未找到最短路径 
		(*D)[V] = G.arc[V0][v];		// 将与v0点有连线的顶点加上权值 
		(*P)[V] = 0;				// 初始化路径数组P为0 
	}
	(*D)[V0] = 0;		// V0到vo的路径为0 
	final[V0] = 1;		// V0到vo无需求路径 
	
	// 开始主循环，每次求得v0到某个顶点v的最短路径 
	for( v=1; v < G.numVertexes; v++ )//循环n-1次 
	{
		min = INFINITY;
		for( w=0; w < G.numVertexes; w++ )
		{
			if( !final[w] && (*D)[w]<min )
			{
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;	// 将目前找到的最近的顶点设为1 
		
		// 修正当前最短路径和距离 
		for( w=0; w < G.numVextexes; w++ )
		{
			// 如果经过v顶点的路径比现在这条路径长度短的话，更新 
			if( !final[w] && (min+G.arc[k][w] < (*D)[w]) )
			{
				(*D)[w] = min + G.arc[k][w];	// 修改路径长度 
				(*p)[w] = k;					// 存放前驱顶点 ，即存放k-w这条边的前驱k点 
			}
		}
	}
}
