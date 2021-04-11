#include <stdio.h>
//正宗冒泡排序
void BubbleSort(int k[], int n)
{
	int i, j, temp, count1=0, count2=0;
	
	for( i=1; i < n; i++ ) 
	{
		for( j=n; j > i; j-- )//从后往前 
		{
			count1++;
			if( k[j-1] > k[j] )
			{
				count2++;
				temp = k[j-1];
				k[j-1] = k[j];//相邻比较 ，会将最小的数排到最后 
				k[j] = temp; 
			}
		}
	}

	printf("总共进行了%d次比较，进行了%d次移动！", count1, count2);
}

int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	BubbleSort(a-1, 10);

	printf("排序后的结果是：");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
