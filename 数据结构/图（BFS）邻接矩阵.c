//邻接矩阵 
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	
	for( i=0; i < G.numVertexes; i++ )
	{
		visited[i] = FALSE;//初始化 
	}
	
	initQueue( &Q );//初始化队列 
	
	for( i=0; i < G.numVertexes; i++ )
	{
		if( !visited[i] )
		{
			printf("%c ", G.vex[i]);
			visited[i] = TRUE;
			EnQueue(&Q, i);//插入队列 
			
			while( !QueueEmpty(Q) )//主要不为空 
			{
				DeQueue(&Q, &i);//弹出队列 
				for( j=0; j < G.numVertexes; j++ )
				{
					if( G.art[i][j]==1 && !visited[j] )
					{
						printf("%c ", G.vex[j]);
						visited[j] = TRUE;
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
}
