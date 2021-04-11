#include <stdio.h>

void swap(int k[], int low, int high)
{
	int temp;

	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}

int Partition(int k[], int low, int high)//一轮分区  
{
	int point;

	point = k[low];//基准点在low处 

	while( low < high )
	{
		while( low < high && k[high] >= point )//右边 
		{
			high--;
		}//退出循环说明找到了比基准点更小的数 或者low就是最小       优化方案！ 
		swap(k, low, high);                                        //k[low]=k[high]; 
		
		while( low < high && k[low] <= point )//左边 
		{
			low++;
		}
		swap(k, low, high);                                      //k[high]=k[low];
	}
                                                                //k[low]=point 
	return low;//返回基准点位置 
}

void QuickSort(int k[], int low, int high)//两个位置标识 
{
	int point;

	if( low < high )//递归 
	{
		point = Partition(k, low, high);//找基准点 

		QuickSort(k, low, point-1);

		QuickSort(k, point+1, high);
	}
}

int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	QuickSort(a-1,1,10);

	printf("排序后的结果是：");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
