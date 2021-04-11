//https://blog.csdn.net/tmylzq187/article/details/51816084
#include <stdio.h>
#define MAXSIZE 10
//ͨ���ȵݹ�ķֽ����У��ٺϲ����о�����˹鲢����
// ʵ�ֹ鲢���������Ľ����ŵ�list1��
void merging(int *list1, int list1_size, int *list2, int list2_size)//ע��list��ָ�� 
{
	int i, j, k, m;
	int temp[list1_size+list2_size];//���ڴ���������� 

	i = j = k = 0;

	while( i < list1_size && j < list2_size )//�Ƚϴ�С������ ������temp�Ķ���������� 
	{
		if( list1[i] <= list2[j] )
		{
			temp[k++] = list1[i++]; 
		}
		else
		{
			temp[k++] = list2[j++];
		}
	}
//�����һ������ȫ��������һ�߻���ʣ�������ʣ�µĶ������ģ�ֱ������temp 
	while( i < list1_size )
	{
		temp[k++] = list1[i++];
	}

	while( j < list2_size )
	{
		temp[k++] = list2[j++];
	}

	for( i=0; i < (list1_size + list2_size); i++ )//ȫ���浽list1 
	{
		list1[i] = temp[i];
	}
}

void MergeSort(int k[], int n)
{
	if( n > 1)
	{
		int *list1 = k;
		int list1_size = n/2;
		int *list2 = k + n/2;//Ҳ����д��&k[n/2] 
		int list2_size = n - list1_size;

		MergeSort(list1, list1_size);//ͨ���ݹ齫�������鶼�ֽ��1��1���� 
		MergeSort(list2, list2_size);

		merging(list1, list1_size, list2, list2_size);
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
