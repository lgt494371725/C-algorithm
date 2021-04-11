//https://blog.csdn.net/qq_38410730/article/details/81667885?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
#include <stdio.h>

#include <string.h>

#define N 15
int item[7]={0};
int max(int i,int j)
{
	if(i>=j)
	{
		return i;
	}
	else
	{
		return j;
	}
}
int i,j;
void traceback(int m[i][j])//找到此时的最优解是放了哪几种物品 
{
    if(i>=0)
    {
	  if(m[i][j]==m[i-1][j])   //如果m(i,j)=m(i-1,j-w(i))+v(i)时，说明装了第i个商品，该商品是最优解组成的一部分，随后我们得回到装该商品之前，即回到V(i-1,j-w(i))；
		{		
			item[i]=0;					//如果m[n][c]=m[n-1][c] ,说明有没有第n件物品都一样,故没有选 
			traceback(m[i-1][j]);
		}
		else if(j-w[i]>=0&&m[i][j]==m[i-1][j-w[i]+v[i]])
		{
			item[i]=1;
			traceback(m[i-1][j-w[i]]);
		}
	}
}
int main()
{
    
	int v[N]={0,8,10,6,3,7,2};//0不算，从第一件到第6件的价值 

    int w[N]={0,4,6,2,2,5,1};//0不算，从第一件到第6件的重量 
    int m[N][N];

    int n=6,c=12;//6是数量，12是重量 

    memset(m,0,sizeof(m));//全部填充为0 

    for( i=1;i<=n;i++)//i表示第i件，j表示背包最大重量 
     {
//从第一行左到右，再从第一行到最后一行，按顺序填补 
        for(j=1;j<=c;j++)
        {
		if(j>=w[i])

                m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);//m[i][j]表示考虑了第1件到第i件，背包重量为j时，能得到的最大价值 

            else

                m[i][j]=m[i-1][j];       
         }

    }        
    for(i=1;i<=n;i++)

    {

        for(j=1;j<=c;j++)
        {

            printf("%2d ",m[i][j]);

        }
			printf("\n");
    }
    traceback(&m[2][3]);

    for(i=1;i<=n;i++)

        printf("%d",item[i]);

    return 0;
}
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
