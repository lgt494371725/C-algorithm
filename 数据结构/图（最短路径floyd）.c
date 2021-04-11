https://blog.csdn.net/qq_35644234/article/details/60875818
#define MAXVEX	9
#define INFINITY	65535

typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

void ShortestPath_Floyd(MGraph G, Pathmatirx *P, ShortPathTable *D)
{
	int v, w, k;
	
	// 初始化D和P 
	for( v=0; v < G.numVertexes; v++ )
	{
		for( w=0; w < G.numVertexes; w++ )
		{
			(*D)[v][w] = G.matirx[v][w];
			(*P)[v][w] = w;//p矩阵表示经过了这个顶点，表示顶点i到顶点j经过了b[i][j]所表示的顶点，如v1，v4=3，表示1到4必须经过3这个顶点 
		}//p矩阵先初始化为自身点即0123456.。 
	}
	

	for( k=0; k < G.numVertexes; k++ )
	{
		for( v=0; v < G.numVertexes; v++ )
		{
			for( w=0; w < G.numVertexes; w++ )
			{
				if( (*D)[v][w] > (*D)[v][k] + (*D)[k][w] )
				{
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					(*P)[v][w] = (*P)[v][k];	//要理解这句话	
				}
			}
		}
	}
}
