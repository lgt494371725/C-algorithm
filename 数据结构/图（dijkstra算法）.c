https://blog.csdn.net/swustzhaoxingda/article/details/84318570
#define MAXVEX	9
#define	INFINITY	65535

typedef	int	Patharc[MAXVEX];			// �洢���·���±� 
typedef int	ShortPathTable[MAXVEX];		// �洢���������·����Ȩֵ�� 

void ShortestPath_Dijkstar(MGraph G, int V0, Patharc *P, ShortPathTable *D)
{
	int v, w, k, min;
	int final[MAXVEX];		// final[w] = 1 ��ʾ�Ѿ���ö���v0��vw�����·�� 
	
	for( v=0; v < G.numVertexes; v++ )
	{
		final[v] = 0;				// ȫ�������ʼ��Ϊδ�ҵ����·�� 
		(*D)[V] = G.arc[V0][v];		// ����v0�������ߵĶ������Ȩֵ 
		(*P)[V] = 0;				// ��ʼ��·������PΪ0 
	}
	(*D)[V0] = 0;		// V0��vo��·��Ϊ0 
	final[V0] = 1;		// V0��vo������·�� 
	
	// ��ʼ��ѭ����ÿ�����v0��ĳ������v�����·�� 
	for( v=1; v < G.numVertexes; v++ )//ѭ��n-1�� 
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
		final[k] = 1;	// ��Ŀǰ�ҵ�������Ķ�����Ϊ1 
		
		// ������ǰ���·���;��� 
		for( w=0; w < G.numVextexes; w++ )
		{
			// �������v�����·������������·�����ȶ̵Ļ������� 
			if( !final[w] && (min+G.arc[k][w] < (*D)[w]) )
			{
				(*D)[w] = min + G.arc[k][w];	// �޸�·������ 
				(*p)[w] = k;					// ���ǰ������ �������k-w�����ߵ�ǰ��k�� 
			}
		}
	}
}
