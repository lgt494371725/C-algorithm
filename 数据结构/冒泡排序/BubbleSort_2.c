#include <stdio.h>
//����ð������
void BubbleSort(int k[], int n)
{
	int i, j, temp, count1=0, count2=0;
	
	for( i=1; i < n; i++ ) 
	{
		for( j=n; j > i; j-- )//�Ӻ���ǰ 
		{
			count1++;
			if( k[j-1] > k[j] )
			{
				count2++;
				temp = k[j-1];
				k[j-1] = k[j];//���ڱȽ� ���Ὣ��С�����ŵ���� 
				k[j] = temp; 
			}
		}
	}

	printf("�ܹ�������%d�αȽϣ�������%d���ƶ���", count1, count2);
}

int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	BubbleSort(a-1, 10);

	printf("�����Ľ���ǣ�");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
