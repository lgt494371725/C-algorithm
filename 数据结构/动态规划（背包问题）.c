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
void traceback(int m[i][j])//�ҵ���ʱ�����Ž��Ƿ����ļ�����Ʒ 
{
    if(i>=0)
    {
	  if(m[i][j]==m[i-1][j])   //���m(i,j)=m(i-1,j-w(i))+v(i)ʱ��˵��װ�˵�i����Ʒ������Ʒ�����Ž���ɵ�һ���֣�������ǵûص�װ����Ʒ֮ǰ�����ص�V(i-1,j-w(i))��
		{		
			item[i]=0;					//���m[n][c]=m[n-1][c] ,˵����û�е�n����Ʒ��һ��,��û��ѡ 
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
    
	int v[N]={0,8,10,6,3,7,2};//0���㣬�ӵ�һ������6���ļ�ֵ 

    int w[N]={0,4,6,2,2,5,1};//0���㣬�ӵ�һ������6�������� 
    int m[N][N];

    int n=6,c=12;//6��������12������ 

    memset(m,0,sizeof(m));//ȫ�����Ϊ0 

    for( i=1;i<=n;i++)//i��ʾ��i����j��ʾ����������� 
     {
//�ӵ�һ�����ң��ٴӵ�һ�е����һ�У���˳��� 
        for(j=1;j<=c;j++)
        {
		if(j>=w[i])

                m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);//m[i][j]��ʾ�����˵�1������i������������Ϊjʱ���ܵõ�������ֵ 

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
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
