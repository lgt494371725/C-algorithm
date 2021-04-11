#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

void MergeSort(int k[], int n)
{
	int i, next, left_min, left_max, right_min, right_max;
	int *temp = (int *)malloc(n * sizeof(int));

	for( i=1; i < n; i*=2 ) //����Ԫ������ 
	{
		for( left_min=0; left_min < n-i; left_min = right_max )//������Ե���ߺ��ұ� 
		{
			right_min = left_max = left_min + i;//�����ǶԵģ������2Ϊ����ʱ���ĸ���Ϊ��min=0 ��max=��min=2����max= 4��
			                                      //4������ʵ���ǵ�5��Ԫ�أ����ڶ���ĵ�һ�������ڵ��� 
			right_max = right_min + i;

			if( right_max > n )//��nΪ����ʱ ����rightmax����nʱ 
			{
				right_max = n;
			}

			next = 0;

			while( left_min < left_max && right_min < right_max )//ִ�е�ĳһ�߶�����tempΪֹ 
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

			while( left_min < left_max )//���������ұߵ������Ѿ�ȫ���洢��ϣ�������黹��ʣ�µ� 
			{
				k[--right_min] = k[--left_max];//��ʱ���ʣ��Ķ�������������������������temp���������Щ�������ŵ���������ұ�
			}//ע�������ǰ ����Ϊ����ǰ���whileѭ������Ϊ���һλ������i=2ʱ����min��0��max��2��ʵ�����ǵ�����Ԫ�أ�����Ҫ�ȼ�1 
//
			while( next > 0 )
			{
				k[--right_min] = temp[--next];//��temp���������ȫ�ŵ�������ߣ�������ǰ���������ͻ�ƴ��һ�����������飬��С���� 
			}
		}
	}
}

int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	MergeSort(a, 10);

	printf("�����Ľ���ǣ�");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
