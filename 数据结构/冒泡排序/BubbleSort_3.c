#include <stdio.h>
//���ַ�����ȱ�ݣ� �������������ʹ����� 
void BubbleSort(int k[], int n)
{
	int i, j, temp, count1=0, count2=0, flag;
	
	flag = 1;//��flag��ģ�Ⲽ������ 
	for( i=0; i < n-1 && flag; i++ )//����ǰ��������е�����£����Լ�С������� 
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

	printf("�ܹ�������%d�αȽϣ�������%d���ƶ���", count1, count2);
}

int main()
{
	int i, a[10] = {1, 0, 2, 3, 4, 9, 6, 8, 5, 7};

	BubbleSort(a, 10);

	printf("�����Ľ���ǣ�");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
