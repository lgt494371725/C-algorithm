
typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode;


typedef struct VertexNode
{
	int in;			// 入度
	int data;
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;

//拓扑排序算法 
// 若GL无回路，则输出拓扑排序并返回OK，否则ERROR 
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;		// 用于栈指针下标索引 
	int count = 0;		// 用于统计输出顶点的个数 
	int *stack;			// 用于存储入度为0的顶点 
	
	stack = (int *)malloc(GL->numVertexes * sizeof(int));
	
	for( i=0; i < GL->numVertexes; i++ )
	{
		if( 0 == GL->adjList[i].in )
		{
			stack[++top] = i;	// 将度为0的顶点下标入栈 
		}
	}
	
	while( 0 != top )//这里栈的使用方法要确认是否可用 
	{
		gettop = stack[top--];	// 出栈 
		printf("%d -> ", GL->adjList[gettop].data);
		count++;				
		
		for( e=GL->adjList[gettop].firstedge; e; e=e->next )
		{
			k = e->adjvex;
			// 注意：x下边这个if条件sh是分析程序的要点 
			// 将k号顶点邻接点的入度-1，因为前驱消除了 
			// 判断-1后是否为0，如果为0入栈 
			if( !(--GL->adjList[k].in) )	
			{
				stack[++top] = k;
			}
		}
	}
	
	if( count < GL->numVertexes )	// 如果count数小于顶点数说明有环 
	{
		return ERROR;
	}
	else
	{
		return OK;
	}
}
