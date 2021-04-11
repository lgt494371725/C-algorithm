#include <stdio.h>
//第一版本冒泡排序 
void BubbleSort(int k[], int n)
{
	int i, j, temp, count1=0, count2=0;
	
	for( i=0; i < n-1; i++ )
	{
		for( j=i+1; j < n; j++ )
		{
			count1++;//并非相邻元素比较，只有第一次比较是 
			if( k[i] > k[j] )//先用下标0的跟其余9个依次比，找到10个元素中最小的，然后是1跟其余8个比。。。。。。排序 
			{
				count2++;
				temp = k[i];
				k[i] = k[j];
				k[j] = temp;
			}
		}
	}
	printf("总共进行了%d次比较，进行了%d次移动！", count1, count2);
}

int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	BubbleSort(a, 10);

	printf("排序后的结果是：");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
