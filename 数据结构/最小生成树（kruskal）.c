//https://blog.csdn.net/junya_zhang/article/details/83584592 
int Find(int *parent, int f)
{
//���±�f��ʼѰ��parent������Ԫ��Ϊ0���±�
	while( parent[f] > 0 )
	{
		f = parent[f];
	}
	
	return f;
}

// Kruskal����С������ 
void MiniSpanTree_Kruskal(MGraph G)
{
	int i, n, m;
	Edge edges[MAGEDGE];	// ����߼����� ����С�ŵ��� 
	int parent[MAXVEX];		// ����parent���������ж��Ƿ��γɻ�· 
	
	for( i=0; i < G.numVertexes; i++ )
	{
		parent[i] = 0;//parent[i]=0,��ζ�Ÿ���ͨ·��������û��·�ˣ��տ�ʼ������䶼��ͨ 
	}
	
	for( i=0; i < G.numEdges; i++ )
	{
		n = Find(parent, edges[i].begin);	// 4 2 0 1 5 3 8 6 6 6 7//�Ӹñߵ���㿪ʼѰ��parent������Ϊ0��Ԫ�ص��±꣬
		m = Find(parent, edges[i].end);		// 7 8 1 5 8 7 6 6 6 7 7//�Ӹñߵ��յ�㿪ʼѰ��parent������Ϊ0��Ԫ�ص��±꣬
		
		if( n != m )		//���m=n˵��������������ߣ���Ӹñߵ������յ����ն��ᵽ��ͬһ���㣬���л�
		{ 
			parent[n] = m;	// ���˱ߵĽ�β��������±�Ϊ����parent���飬��ʾ�ܹ���n��ͨ��m 
			printf("(%d, %d) %d ", edges[i].begin, edges[i].end, edges[i].weight);
		}
	}
}
