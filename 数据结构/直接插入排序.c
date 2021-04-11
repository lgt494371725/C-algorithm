#include <stdio.h>
//基本有序或者记录数少的情况用 
void InsertSort(int k[], int n)
{
	int i, j, temp;

	for( i=1; i < n; i++ )
	{
		if( k[i] < k[i-1] )//如果乱序，把小的数放到temp 
		{
			temp = k[i];
										//当j减到-1时就会退出循环 
			for( j=i-1; j>=0&&k[j] > temp; j-- )//比如这个数列。5和2乱了，就把2放到temp，5放到2的地方，2放到5的地方，下一次就从第2个位置开始 
			{                          //到0和6，将0计入temp，6向前，然后5，2与0进行比较 
				k[j+1] = k[j];//里面的数据前进一格 
			}

			k[j+1] = temp;//注意要加1 
		}
	}
}

int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	InsertSort(a, 10);

	printf("排序后的结果是：");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
