#include <stdio.h>
//这种方法有缺陷！ 如这种情况排序就错误了 
void BubbleSort(int k[], int n)
{
	int i, j, temp, count1=0, count2=0, flag;
	
	flag = 1;//用flag来模拟布尔类型 
	for( i=0; i < n-1 && flag; i++ )//在提前排序好数列的情况下，可以减小多余次数 
	{
		for( j=n-1; j > i; j-- )
		{
			count1++;
			flag = 0;
			if( k[j-1] > k[j] )
			{
				count2++;
				temp = k[j-1];
				k[j-1] = k[j];
				k[j] = temp;
				flag = 1;
			}
		}
	}

	printf("总共进行了%d次比较，进行了%d次移动！", count1, count2);
}

int main()
{
	int i, a[10] = {1, 0, 2, 3, 4, 9, 6, 8, 5, 7};

	BubbleSort(a, 10);

	printf("排序后的结果是：");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
