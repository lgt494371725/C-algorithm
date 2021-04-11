//https://blog.csdn.net/codes_first/article/details/78474226 四种八皇后解法 
#include <stdio.h>
#include<string.h> 
//p34 
int count = 0;

int notDanger( int row, int j, int (*chess)[8] )
{
	int i, k, flag1=0, flag2=0, flag3=0, flag4=0, flag5=0;
//因为底下会将整行都初始化，所以不用判断行 
	// 判断该列有没有危险  
	for( i=0; i < 8; i++ )
	{
		if( *(*(chess+i)+j) != 0 )
		{
			flag1 = 1;
			break;
		}
	}

	// 判断左上方 
	for( i=row, k=j; i>=0 && k>=0; i--, k-- )
	{
		if( *(*(chess+i)+k) != 0 )
		{
			flag2 = 1;
			break; 
		}
	}

	// 判断右下方 
	for( i=row, k=j; i<8 && k<8; i++, k++ )
	{
		if( *(*(chess+i)+k) != 0 )
		{
			flag3 = 1;
			break;
		}
	}

	// 判断右上方 
	for( i=row, k=j; i>=0 && k<8; i--, k++ )
	{
		if( *(*(chess+i)+k) != 0 )
		{
			flag4 = 1;
			break;
		}
	}

	// 判断左下方 
	for( i=row, k=j; i<8 && k>=0; i++, k-- )
	{
		if( *(*(chess+i)+k) != 0 )
		{
			flag5 = 1;
			break;
		}
	}

	if( flag1 || flag2 || flag3 || flag4 || flag5 )//若其中任何一个有皇后 
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// row: 开始行 
// n: 列 
// (*chess)[8]: 指向每一行 
void EightQueen( int row, int n, int (*chess)[8] )
{
	int chess2[8][8], i, j;//临时棋盘 
//需要棋盘的理由： 
	for( i=0; i < 8; i++ )
	{
		for( j=0; j < 8; j++ )
		{
			chess2[i][j] = chess[i][j];
		}
	}

	if( 8 == row )
	{
		printf("第%d 种\n", count+1);
		for( i=0; i < 8; i++ )
		{
			for( j=0; j < 8; j++ )
			{
				printf("%d ", *(*(chess2+i)+j));
			}
			printf("\n");
		}
		printf("\n");
		count++;
	}
	else
	{ 
		for( j=0; j < n; j++ )//j是列 
		{
			if( notDanger( row, j, chess ) ) // 判断位置是否危险，没危险则继续 
			{
				for( i=0; i < 8; i++ )
				{
					*(*(chess2+row)+i) = 0;//让整行其他位置都为0，再次初始化棋盘 
				}
//需要初始化棋盘的理由：因为填棋盘的顺序。首先从0，0开始，填入1，然后进入1，0进入了递归，先不管递归情况。回到循环，此时j=1，
//j=1，此时坐标0，1，判断后再填入，没有判断行，此时0，0位置是1，已经进入递归了，要把1给刷新掉。外层for循环从左到右，递归里从上到下 
				*(*(chess2+row)+j) = 1;//安全位置放皇后 

				EightQueen( row+1, n, chess2 );//用的递归，不会重复 
			}
		} 
	}
}

int main()
{
	int chess[8][8], i, j;

	memset(chess,0,sizeof(chess));

	EightQueen( 0, 8, chess );

	printf("总共有%d 方法\n\n", count);

	return 0;
}
