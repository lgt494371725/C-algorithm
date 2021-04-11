// ********************************
// By 灏忕敳楸硷紝http://www.fishc.com
// ********************************

#include <stdio.h>

#define MAXSIZE 20

void fibonacci(int *f)
{
	int i;

	f[0] = 1;
	f[1] = 1;
	
	for(i=2; i < MAXSIZE; ++i)//这里++i和i++其实是一样的 
	{
		f[i] = f[i-2] + f[i-1];//将数组填满斐波那契数 

	}
}

int fibonacci_search(int *a,int key,int n)//n是数组的长度，这里用指针是因为要修改数组 
{
	int low = 0;
	int high = n - 1;
	int mid = 0;
	int k = 0;
	int F[MAXSIZE];
	int i;

	fibonacci(F);//将F数组填满斐波那契数 
	
	while( n > F[k]-1 ) //总之就是n的个数必须是斐波那契数减一才能用这个查找法 
	{
		++k;//确定大于数组长度的最小斐波那契数列 
	}

	for( i=n; i <= F[k]-1; ++i)
	{
		a[i] = a[high];//将补充的长度都设置为high的大小 
	}

	while( low <= high )//插值查找循环条件也是用这个 
	{
		mid = low + F[k-1] - 1;//黄金比例点，如13，黄金点就是第8个，因为是数组，减一就是第七个 

		if( a[mid] > key )//说明key在low与黄金点之间 ，即0与7之间 
		{
			high = mid - 1;
			k = k - 1;//把k减小一级 
		}
		else if( a[mid] < key )//说明key在high与黄金点之间 ，即8与12之间  
		{
			low = mid + 1;
			k = k - 2;
		}
		else//即值相等时 
		{
			if( mid <= high ) //因为有补充过长度，所以需要进行判断 
			{
				return mid;
			}
			else//mid大于high，说明mid在填充的部分，这部分值就是high位置的值 
			{
				return high;
			}
		}
	}

	return -1;
}
//注意这种算法数字也是按照大小顺序的 
int main()
{
	
	int a[MAXSIZE] = {1, 5, 15, 22, 25, 31, 39, 42, 47, 49, 59, 68, 88};
	int key;
	int pos;

	printf("请输入数据");
	scanf("%d", &key);
	
	pos = fibonacci_search(a, key, 13);
	
	if( pos != -1 )
	{
		printf("\n数据：%d 位置 %d\n\n", key, pos);
	}
	else
	{
		printf("\nO~No~~查找失败:%d\n\n", key);
	}
		
	return 0;
}
