https://blog.csdn.net/qq_35644234/article/details/60875818
#define MAXVEX	9
#define INFINITY	65535

typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

void ShortestPath_Floyd(MGraph G, Pathmatirx *P, ShortPathTable *D)
{
	int v, w, k;
	
	// ��ʼ��D��P 
	for( v=0; v < G.numVertexes; v++ )
	{
		for( w=0; w < G.numVertexes; w++ )
		{
			(*D)[v][w] = G.matirx[v][w];
			(*P)[v][w] = w;//p�����ʾ������������㣬��ʾ����i������j������b[i][j]����ʾ�Ķ��㣬��v1��v4=3����ʾ1��4���뾭��3������� 
		}//p�����ȳ�ʼ��Ϊ����㼴0123456.�� 
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
					(*P)[v][w] = (*P)[v][k];	//Ҫ�����仰	
				}
			}
		}
	}
}
