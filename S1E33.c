#include <stdio.h>

void createMatrix(int n);

void createMatrix(int n)
{
    int i,j,oj,oi,num,max;
	max=n*n;
	int matrix[n][n];//����n��δ֪����������ֱ����ƽ����={0}��ʼ�� 
	 for (i = 0; i < n; i++)
        {
                for (j = 0; j < n; j++)
                {
					matrix[i][j]=0;
				} 
        }
	matrix[0][n/2]=1;
	i=0,j=n/2;
	//ע����Щ�����ŵ�λ�ã��Ƿ��Ѿ����������ʼ���� 
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
			j=oj;//����������Ҫ���� 
			matrix[i][j]=num;//���ݹ���oj��ֱ�ӷ��ڴ˴�������  
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

        printf("������һ��3���ϵ�����:");
        scanf("%d", &n);
        createMatrix(n);
        return 0;
}
