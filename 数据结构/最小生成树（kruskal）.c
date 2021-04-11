//https://blog.csdn.net/junya_zhang/article/details/83584592 
int Find(int *parent, int f)
{
//从下标f开始寻找parent数组中元素为0的下标
	while( parent[f] > 0 )
	{
		f = parent[f];
	}
	
	return f;
}

// Kruskal，最小生成树 
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAGEDGE];	// 定义边集数组 ，从小排到大 
	int parent[MAXVEX];		// 定义parent数组用来判断是否形成环路 
	
	for( i=0; i < G.numVertexes; i++ )
	{
		parent[i] = 0;//parent[i]=0,意味着该连通路继续往下没有路了，刚开始各顶点间都不通 
	}
	
	for( i=0; i < G.numEdges; i++ )
	{
		n = Find(parent, edges[i].begin);	// 4 2 0 1 5 3 8 6 6 6 7//从该边的起点开始寻找parent数组中为0的元素的下标，
		m = Find(parent, edges[i].end);		// 7 8 1 5 8 7 6 6 6 7 7//从该边的终点点开始寻找parent数组中为0的元素的下标，
		
		if( n != m )		//如果m=n说明如果连接这条边，则从该边的起点和终点最终都会到达同一顶点，即有环
		{ 
			parent[n] = m;	// 将此边的结尾顶点放入下标为起点的parent数组，表示能够从n联通到m 
			printf("(%d, %d) %d ", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}
