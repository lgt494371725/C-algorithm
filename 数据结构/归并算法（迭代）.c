#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

void MergeSort(int k[], int n)
{
	int i, next, left_min, left_max, right_min, right_max;
	int *temp = (int *)malloc(n * sizeof(int));

	for( i=1; i < n; i*=2 ) //分组元素数量 
	{
		for( left_min=0; left_min < n-i; left_min = right_max )//两半各自的左边和右边 
		{
			right_min = left_max = left_min + i;//这样是对的，比如比2为分组时，四个点为左min=0 左max=右min=2，右max= 4，
			                                      //4在数组实际是第5个元素，即第二组的第一个，便于迭代 
			right_max = right_min + i;

			if( right_max > n )//当n为奇数时 ，当rightmax大于n时 
			{
				right_max = n;
			}

			next = 0;

			while( left_min < left_max && right_min < right_max )//执行到某一边都存入temp为止 
			{
				if( k[left_min] < k[right_min] )
				{
					temp[next++] = k[left_min++];
				}
				else
				{
					temp[next++] = k[right_min++];
				}
			}

			while( left_min < left_max )//这个情况是右边的数组已经全部存储完毕，左边数组还有剩下的 
			{
				k[--right_min] = k[--left_max];//此时左边剩余的都是最大的数，其他数都存在了temp数组里，将这些最大的数放到数组的最右边
			}//注意减号在前 ，因为根据前面的while循环数据为虚高一位，比如i=2时，左min是0，max是2，实际上是第三个元素，所以要先减1 
//
			while( next > 0 )
			{
				k[--right_min] = temp[--next];//讲temp数组里的数全放到数组左边，这样与前面最大的数就会拼成一个完整的数组，从小到大 
			}
		}
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
