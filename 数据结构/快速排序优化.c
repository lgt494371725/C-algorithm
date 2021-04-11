#include <stdio.h>
#include<stdlib.h>
void swap(int k[], int low, int high)
{
	int temp;

	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}
//�Կ�����������Ż�����ֹ��ʱ��׼��������� 
int Partition(int k[], int low, int high)
{
	int point;
 	int m=low+(high-low) /2;
 	if(k[low]>k[high])
 	{
 		swap(k,low,high);
	 }
	 if(k[m]>k[high])
	 {
	 	swap(k,m,high);
	 }
	 if(k[m]>k[low])
 	{
 		swap(k,m,low);//ʹlow��Ŵ�С�м���Ǹ�ֵ 
	 }
	point = k[low];//��׼����low�� 

	while( low < high )
	{
		while( low < high && k[high] >= point )//�ұ� 
		{
			high--;
		}//�˳�ѭ��˵���ҵ��˱Ȼ�׼���С���� ����low������С 
		swap(k, low, high);
		
		while( low < high && k[low] <= point )//��� 
		{
			low++;
		}
		swap(k, low, high);
	}

	return low;//���ػ�׼��λ�� 
}

void QuickSort(int k[], int low, int high)//����λ�ñ�ʶ 
{
	int point;

	if( low < high )
	{
		point = Partition(k, low, high);//�һ�׼�� 

		QuickSort(k, low, point-1);

		QuickSort(k, point+1, high);
	}
}


int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};
	int size=sizeof(a)/sizeof(a[1]);
	QuickSort(a-1, 1,size);

	printf("�����Ľ���ǣ�");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
