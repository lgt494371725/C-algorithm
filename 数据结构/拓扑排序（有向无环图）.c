
typedef struct EdgeNode
{
	int adjvex;
	struct EdgeNode *next;
}EdgeNode;


typedef struct VertexNode
{
	int in;			// ���
	int data;
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;

//���������㷨 
// ��GL�޻�·��������������򲢷���OK������ERROR 
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;		// ����ջָ���±����� 
	int count = 0;		// ����ͳ���������ĸ��� 
	int *stack;			// ���ڴ洢���Ϊ0�Ķ��� 
	
	stack = (int *)malloc(GL->numVertexes * sizeof(int));
	
	for( i=0; i < GL->numVertexes; i++ )
	{
		if( 0 == GL->adjList[i].in )
		{
			stack[++top] = i;	// ����Ϊ0�Ķ����±���ջ 
		}
	}
	
	while( 0 != top )//����ջ��ʹ�÷���Ҫȷ���Ƿ���� 
	{
		gettop = stack[top--];	// ��ջ 
		printf("%d -> ", GL->adjList[gettop].data);
		count++;				
		
		for( e=GL->adjList[gettop].firstedge; e; e=e->next )
		{
			k = e->adjvex;
			// ע�⣺x�±����if����sh�Ƿ��������Ҫ�� 
			// ��k�Ŷ����ڽӵ�����-1����Ϊǰ�������� 
			// �ж�-1���Ƿ�Ϊ0�����Ϊ0��ջ 
			if( !(--GL->adjList[k].in) )	
			{
				stack[++top] = k;
			}
		}
	}
	
	if( count < GL->numVertexes )	// ���count��С�ڶ�����˵���л� 
	{
		return ERROR;
	}
	else
	{
		return OK;
	}
}
