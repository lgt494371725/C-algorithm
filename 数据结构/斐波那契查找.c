// ********************************
// By 小甲鱼，http://www.fishc.com
// ********************************

#include <stdio.h>

#define MAXSIZE 20

void fibonacci(int *f)
{
	int i;

	f[0] = 1;
	f[1] = 1;
	
	for(i=2; i < MAXSIZE; ++i)//����++i��i++��ʵ��һ���� 
	{
		f[i] = f[i-2] + f[i-1];//����������쳲������� 

	}
}

int fibonacci_search(int *a,int key,int n)//n������ĳ��ȣ�������ָ������ΪҪ�޸����� 
{
	int low = 0;
	int high = n - 1;
	int mid = 0;
	int k = 0;
	int F[MAXSIZE];
	int i;

	fibonacci(F);//��F��������쳲������� 
	
	while( n > F[k]-1 ) //��֮����n�ĸ���������쳲���������һ������������ҷ� 
	{
		++k;//ȷ���������鳤�ȵ���С쳲��������� 
	}

	for( i=n; i <= F[k]-1; ++i)
	{
		a[i] = a[high];//������ĳ��ȶ�����Ϊhigh�Ĵ�С 
	}

	while( low <= high )//��ֵ����ѭ������Ҳ������� 
	{
		mid = low + F[k-1] - 1;//�ƽ�����㣬��13���ƽ����ǵ�8������Ϊ�����飬��һ���ǵ��߸� 

		if( a[mid] > key )//˵��key��low��ƽ��֮�� ����0��7֮�� 
		{
			high = mid - 1;
			k = k - 1;//��k��Сһ�� 
		}
		else if( a[mid] < key )//˵��key��high��ƽ��֮�� ����8��12֮��  
		{
			low = mid + 1;
			k = k - 2;
		}
		else//��ֵ���ʱ 
		{
			if( mid <= high ) //��Ϊ�в�������ȣ�������Ҫ�����ж� 
			{
				return mid;
			}
			else//mid����high��˵��mid�����Ĳ��֣��ⲿ��ֵ����highλ�õ�ֵ 
			{
				return high;
			}
		}
	}

	return -1;
}
//ע�������㷨����Ҳ�ǰ��մ�С˳��� 
int main()
{
	
	int a[MAXSIZE] = {1, 5, 15, 22, 25, 31, 39, 42, 47, 49, 59, 68, 88};
	int key;
	int pos;

	printf("����������");
	scanf("%d", &key);
	
	pos = fibonacci_search(a, key, 13);
	
	if( pos != -1 )
	{
		printf("\n���ݣ�%d λ�� %d\n\n", key, pos);
	}
	else
	{
		printf("\nO~No~~����ʧ��:%d\n\n", key);
	}
		
	return 0;
}
