#include<stdio.h> 
// Prim�㷨������С������ 
#define MAXVEX 100
void MiniSpanTree_Prim(Graph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		// ������ض����±� ��adjvex��2��=1���ͱ�ʾ��2�����Ķ�����1 
	int lowcost[MAXVEX];	// ������ض�����Ȩֵ 
	
	lowcost[0] = 0;			// V0��Ϊ��С�������ĸ���ʼ������ȨֵΪ0 
	adjvex[0] = 0;			// V0��һ������ 
	
	// ��ʼ������ 
	for( i=1; i < G.numvexs; i++ )
	{
		lowcost[i] = G.edge[0][i];	// ���ڽӾ����0������Ȩֵ�ȼ������� 
		adjvex[i] = 0;				//��ʼ��ȫ����Ϊv0���±� �������v1��ʼ�Ͷ���ʼ��Ϊ1 
	}
	
	// ����������С�������Ĺ��� 
	for( i=1; i < G.numvexs; i++ )
	{
		min = INFINITY;		// ��ʼ����СȨֵλ65535�Ȳ�������ֵ 
		j = 1;
		k = 0;
		
		// ����ȫ������ 
		while( j < G.numvexs )
		{
			// �ҳ�lowcost�����Ѵ洢����СȨֵ 
			if( lowcost[j]!=0 && lowcost[j] < min )
			{
				min = lowcost[j];
				k = j;		// �����ֵ���СȨֵ���±����k����ʹ�� 
			}
			j++;
		}
		
		// ��ӡ��ǰ�������Ȩֵ��С�ı� 
		printf("(%d,%d)", adjvex[k], k);//��k����������һ������
		lowcost[k] = 0;		// ����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ�������񣬽�����һ������ı��� 
		
		// �ڽӾ���k���������ȫ������ 
		for( j=1; j < G.numvexs; j++ )
		{//lowcost��=0��δ���ʹ�    //�����������Ͻ�˹��������ͬ�ĵط�����Ҫ������ 
			if( lowcost[j]!=0 && G.edge[k][j] < lowcost[j] )//��δ���ʹ���ͬʱ����������ĵ���Ȩֵ��С�� 
			{                             
				lowcost[j] = G.edge[k][j];
				adjvex[j] = k;	//��j����������һ��������k 
			}
		}
	}
}






