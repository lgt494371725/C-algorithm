#include<stdio.h> 
// Prim算法生成最小生成树 
#define MAXVEX 100
void MiniSpanTree_Prim(Graph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		// 保存相关顶点下标 ，adjvex【2】=1，就表示与2相连的顶点是1 
	int lowcost[MAXVEX];	// 保存相关顶点间的权值 
	
	lowcost[0] = 0;			// V0作为最小生成树的根开始遍历，权值为0 
	adjvex[0] = 0;			// V0第一个加入 
	
	// 初始化操作 
	for( i=1; i < G.numvexs; i++ )
	{
		lowcost[i] = G.edge[0][i];	// 将邻接矩阵第0行所有权值先加入数组 
		adjvex[i] = 0;				//初始化全部先为v0的下标 ，如果从v1开始就都初始化为1 
	}
	
	// 真正构造最小生成树的过程 
	for( i=1; i < G.numvexs; i++ )
	{
		min = INFINITY;		// 初始化最小权值位65535等不可能数值 
		j = 1;
		k = 0;
		
		// 遍历全部顶点 
		while( j < G.numvexs )
		{
			// 找出lowcost数组已存储的最小权值 
			if( lowcost[j]!=0 && lowcost[j] < min )
			{
				min = lowcost[j];
				k = j;		// 将发现的最小权值的下标存入k，待使用 
			}
			j++;
		}
		
		// 打印当前顶点边中权值最小的边 
		printf("(%d,%d)", adjvex[k], k);//跟k点相连的上一个顶点
		lowcost[k] = 0;		// 将当前顶点的权值设置为0，表示此顶点已经完成任务，进行下一个顶点的遍历 
		
		// 邻接矩阵k行逐个遍历全部顶点 
		for( j=1; j < G.numvexs; j++ )
		{//lowcost！=0即未访问过    //这个部分是与迪杰斯特拉法不同的地方，重要！！！ 
			if( lowcost[j]!=0 && G.edge[k][j] < lowcost[j] )//找未访问过的同时连接两个点的点且权值最小的 
			{                             
				lowcost[j] = G.edge[k][j];
				adjvex[j] = k;	//跟j点相连的上一个顶点是k 
			}
		}
	}
}






