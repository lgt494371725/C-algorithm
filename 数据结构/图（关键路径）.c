
typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode;


typedef struct VertexNode
{
	int in;			
	int data;
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;

int *etv, *ltv;
int *stack2;			// 用于存储拓排序的栈 
int top2;				//栈顶指针 

// 拓扑排序算法 
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
	
	// 初始化etv都为0 
	top2 = 0;
	etv = (int *)malloc(GL->numVertexes*sizeof(int));
	for( i=0; i < GL->numVertexes; i++ )
	{
		etv[i] = 0;
	}
	stack2 = (int *)malloc(GL->numVertexes*sizeof(int));
	
	while( 0 != top )
	{
		gettop = stack[top--];		//出栈 
		// printf("%d -> ", GL->adjList[gettop].data); 
		stack2[++top2] = gettop;	// 保存拓扑序列排序 C1 C2 C3 C4 .... C9
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
			
			if( (etv[gettop]+e->weight) > etv[k] )
			{
				etv[k] = etv[gettop] + e->weight;
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


void CriticalPath(GraphAdjList GL)
{
	EdgeNode *e;
	int i, gettop, k, j;
	int ete, lte;
	

	TopologicalSort(GL);
	
	//初始化ltv都为汇点的时间 
	ltv = (int *)malloc(GL->numVertexes*sizeof(int));
	for( i=0; i < GL->numVertexes; i++ )
	{
		ltv[i] = etv[GL->numVertexes-1];
	}
	
	//从终点倒过来计算ltv 
	while( 0 != top2 )
	{
		gettop = stack2[top2--];	//第一个出栈是终点 ，终点（C9）无后续点，弹C8.。。 
		for( e=GL->adjList[gettop].firstedge; e; e=e->next )
		{
			k = e->adjvex;
			if( (ltv[k] - e->weight) < ltv[gettop] )
			{
				ltv[gettop] = ltv[k] - e->weight;
			}
		}
	}
	
//通过etv和ltv求ete和lte 
	for( j=0; j < GL->numVertexes; j++ )
	{
		for( e=GL->adjList[j].firstedge; e; e=e->next )
		{
			k = e->adjvex;
			ete = etv[j];
			lte = ltv[k] - e->weight;
			
			if( ete == lte )
			{
				printf("<v%d,v%d> length: %d , ", GL->adjList[j].data, GL->adjList[k].data, e->weight );
			}
		}
	}
}
