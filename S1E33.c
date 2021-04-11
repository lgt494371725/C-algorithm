#include <stdio.h>

void createMatrix(int n);

void createMatrix(int n)
{
    int i,j,oj,oi,num,max;
	max=n*n;
	int matrix[n][n];//这里n是未知参数，不可直接用平常的={0}初始化 
	 for (i = 0; i < n; i++)
        {
                for (j = 0; j < n; j++)
                {
					matrix[i][j]=0;
				} 
        }
	matrix[0][n/2]=1;
	i=0,j=n/2;
	//注意这些变量放的位置，是否会把矩阵坐标给初始化了 
	for(num=2;num<=max;num++)
	{
		oi = i;
 		oj = j;
		i = i - 1;
        j = j + 1;
		if(i<0)
		{
			i=n-1;
		}
		if(j>n-1)
		{
			j=0;
		}
		if(matrix[i][j]==0)
		{
		matrix[i][j]=num;
		}
		else
		{
			i=oi+1;
			j=oj;//这里至关重要！！ 
			matrix[i][j]=num;//根据规律oj数直接放在此处不能用  
		}
	}
	 for (i = 0; i < n; i++)
        {
                for (j = 0; j < n; j++)
                {
                        printf("%2d   ", matrix[i][j]);
                }
                putchar('\n');
        }
}

int main(void)
{
        int n;

        printf("请输入一个3以上的奇数:");
        scanf("%d", &n);
        createMatrix(n);
        return 0;
}
