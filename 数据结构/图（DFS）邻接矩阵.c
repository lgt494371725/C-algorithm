

#define TRUE 1
#define FALSE 0
#define MAX 256

typedef int Boolean;	// TRUE��ʾ�ѷ��ʣ�FALSE��ʾ��δ���� 
Boolean visited[MAX];	//�������ʾ��Щ���㱻���ʹ� 
void DFS(MGraph G, int i)
{
	int j;
	
	visited[i] = TRUE;			//��Ǹö�λ���Ѿ����ʹ� 
	printf("%c ", G.vexs[i]);	// ����ö�����Ϣ 
	for( j=0; j < G.numVertexes; j++ )
	{
		if( G.arc[i][j]==1 && !visited[j] )//ֻ�иö���δ���ʹ����������������ӲŻ���� 
		{
			DFS(G, j);			// �ݹ���� 
		}
	}
}

void DFSTraverse(MGraph G)
{
	int i;
	
	for( i=0; i < G.numVertexes; i++ )
	{
		visited[i] = FALSE;		// ��ʼ�����飬��δ���ʹ� 
	}
	
	for( i=0; i < G.numVertexes; i++ )//�����в���ͨ��ͼ���ֵ���� 
	{
		if( !visited[i] )		// ��δ�����ʹ�����ʼ���� 
		{
			DFS(G, i);
		}
	}
}
