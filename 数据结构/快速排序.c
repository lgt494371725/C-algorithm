#include <stdio.h>

void swap(int k[], int low, int high)
{
	int temp;

	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}

int Partition(int k[], int low, int high)//һ�ַ���  
{
	int point;

	point = k[low];//��׼����low�� 

	while( low < high )
	{
		while( low < high && k[high] >= point )//�ұ� 
		{
			high--;
		}//�˳�ѭ��˵���ҵ��˱Ȼ�׼���С���� ����low������С       �Ż������� 
		swap(k, low, high);                                        //k[low]=k[high]; 
		
		while( low < high && k[low] <= point )//��� 
		{
			low++;
		}
		swap(k, low, high);                                      //k[high]=k[low];
	}
                                                                //k[low]=point 
	return low;//���ػ�׼��λ�� 
}

void QuickSort(int k[], int low, int high)//����λ�ñ�ʶ 
{
	int point;

	if( low < high )//�ݹ� 
	{
		point = Partition(k, low, high);//�һ�׼�� 

		QuickSort(k, low, point-1);

		QuickSort(k, point+1, high);
	}
}

int main()
{
	int i, a[10] = {5, 2, 6, 0, 3, 9, 1, 7, 4, 8};

	QuickSort(a-1,1,10);

	printf("�����Ľ���ǣ�");
	for( i=0; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
