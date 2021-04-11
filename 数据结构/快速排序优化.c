#include <stdio.h>
#include<stdlib.h>
void swap(int k[], int low, int high)
{
	int temp;

	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}
//对快速排序进行优化，防止有时基准点在最边上 
int Partition(int k[], int low, int high)
{
	int point;
 	int m=low+(high-low) /2;
 	if(k[low]>k[high])
 	{
 		swap(k,low,high);
	 }
	 if(k[m]>k[high])
	 {
	 	swap(k,m,high);
	 }
	 if(k[m]>k[low])
 	{
 		swap(k,m,low);//使low存放大小中间的那个值 
	 }
	point = k[low];//基准点在low处 

	while( low < high )
	{
		while( low < high && k[high] >= point )//右边 
		{
			high--;
		}//退出循环说明找到了比基准点更小的数 或者low就是最小 
		swap(k, low, high);
		
		while( low < high && k[low] <= point )//左边 
		{
			low++;
		}
		swap(k, low, high);
	}

	return low;//返回基准点位置 
}

void QuickSort(int k[], int low, int high)//两个位置标识 
{
	int point;

	if( low < high )
	{
		point = Partition(k, low, high);//找基准点 

		QuickSort(k, low, point-1);

		QuickSort(k, point+1, high);
	}
}


int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};
	int size=sizeof(a)/sizeof(a[1]);
	QuickSort(a-1, 1,size);

	printf("排序后的结果是：");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
