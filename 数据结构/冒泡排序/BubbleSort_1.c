#include <stdio.h>
//��һ�汾ð������ 
void BubbleSort(int k[], int n)
{
	int i, j, temp, count1=0, count2=0;
	
	for( i=0; i < n-1; i++ )
	{
		for( j=i+1; j < n; j++ )
		{
			count1++;//��������Ԫ�رȽϣ�ֻ�е�һ�αȽ��� 
			if( k[i] > k[j] )//�����±�0�ĸ�����9�����αȣ��ҵ�10��Ԫ������С�ģ�Ȼ����1������8���ȡ��������������� 
			{
				count2++;
				temp = k[i];
				k[i] = k[j];
				k[j] = temp;
			}
		}
	}
	printf("�ܹ�������%d�αȽϣ�������%d���ƶ���", count1, count2);
}

int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	BubbleSort(a, 10);

	printf("�����Ľ���ǣ�");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
