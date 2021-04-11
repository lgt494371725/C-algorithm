//https://blog.csdn.net/qq_39207948/article/details/80006224
#include <stdio.h>

void shellSort(int k[], int n)
{
	int i, j, temp;
	int gap = n;

	while(gap > 1)
	{
		gap = gap/3 + 1;

		for( i=gap; i < n; i++ )//把gap给i，从每一组最后一个往前推 
		{
			if( k[i] < k[i-gap] )//不用实际分组，如果乱序了，就进行局部直接插入排序 
			{
				temp = k[i];

				for( j=i-gap;j>=0&& k[j] > temp; j-=gap )//这里是局部直接插入排序 
				{
					k[j+gap] = k[j];
				}

				k[j+gap] = temp;
			}
		}
	}
}

int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	shellSort(a, 10);

	printf("排序后的结果是：");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
