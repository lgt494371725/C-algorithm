#include <stdio.h>
//����������߼�¼���ٵ������ 
void InsertSort(int k[], int n)
{
	int i, j, temp;

	for( i=1; i < n; i++ )
	{
		if( k[i] < k[i-1] )//������򣬰�С�����ŵ�temp 
		{
			temp = k[i];
										//��j����-1ʱ�ͻ��˳�ѭ�� 
			for( j=i-1; j>=0&&k[j] > temp; j-- )//����������С�5��2���ˣ��Ͱ�2�ŵ�temp��5�ŵ�2�ĵط���2�ŵ�5�ĵط�����һ�ξʹӵ�2��λ�ÿ�ʼ 
			{                          //��0��6����0����temp��6��ǰ��Ȼ��5��2��0���бȽ� 
				k[j+1] = k[j];//���������ǰ��һ�� 
			}

			k[j+1] = temp;//ע��Ҫ��1 
		}
	}
}

int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	InsertSort(a, 10);

	printf("�����Ľ���ǣ�");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
