//https://blog.csdn.net/tmylzq187/article/details/51816084
#include <stdio.h>
#define MAXSIZE 10
//通过先递归的分解数列，再合并数列就完成了归并排序。
// 实现归并，并把最后的结果存放到list1里
void merging(int *list1, int list1_size, int *list2, int list2_size)//注意list是指针 
{
	int i, j, k, m;
	int temp[list1_size+list2_size];//用于存放排序后的数 

	i = j = k = 0;

	while( i < list1_size && j < list2_size )//比较大小，排序 ，进入temp的都是排完序的 
	{
		if( list1[i] <= list2[j] )
		{
			temp[k++] = list1[i++]; 
		}
		else
		{
			temp[k++] = list2[j++];
		}
	}
//会出现一遍数组全部进入另一边还有剩的情况，剩下的都是最大的，直接填入temp 
	while( i < list1_size )
	{
		temp[k++] = list1[i++];
	}

	while( j < list2_size )
	{
		temp[k++] = list2[j++];
	}

	for( i=0; i < (list1_size + list2_size); i++ )//全部存到list1 
	{
		list1[i] = temp[i];
	}
}

void MergeSort(int k[], int n)
{
	if( n > 1)
	{
		int *list1 = k;
		int list1_size = n/2;
		int *list2 = k + n/2;//也可以写成&k[n/2] 
		int list2_size = n - list1_size;

		MergeSort(list1, list1_size);//通过递归将左右数组都分解成1个1个的 
		MergeSort(list2, list2_size);

		merging(list1, list1_size, list2, list2_size);
	}
}

int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	MergeSort(a, 10);

	printf("排序后的结果是：");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
