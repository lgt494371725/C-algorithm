//https://blog.csdn.net/qq_39207948/article/details/80006224
#include <stdio.h>

void shellSort(int k[], int n)
{
	int i, j, temp;
	int gap = n;

	while(gap > 1)
	{
		gap = gap/3 + 1;

		for( i=gap; i < n; i++ )//��gap��i����ÿһ�����һ����ǰ�� 
		{
			if( k[i] < k[i-gap] )//����ʵ�ʷ��飬��������ˣ��ͽ��оֲ�ֱ�Ӳ������� 
			{
				temp = k[i];

				for( j=i-gap;j>=0&& k[j] > temp; j-=gap )//�����Ǿֲ�ֱ�Ӳ������� 
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

	printf("�����Ľ���ǣ�");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
