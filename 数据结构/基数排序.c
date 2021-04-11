//��������Ͱ���� 
#include<math.h>
#include<stdio.h> 	
void bucketSort(int *p, int n); 
void sort2(int *p, int n, int loop); 

//��������
void bucketSort(int a[], int n)
{
    //��ȡ�����е������
    int maxNum = findMaxNum(a, n);
    //��ȡ�������λ��������Ҳ���ٷ���Ĵ�����
    int looptimes=0;//��ȡ���ֵ�λ��
    int i;
     while(maxNum)
    {
        looptimes++;
        maxNum/= 10;
    }
    //��ÿһλ����Ͱ����
    for(i = 1; i <= looptimes; i++)
    {
        sort2(a, n, i);
    }
}
//��ȡ���ֵ�λ��

//��ѯ�����е������
int findMaxNum(int a[], int n)
{
    int i;
    int max = 0;
    for(i = 0; i < n; i++)
    {
        if(a[i] > max) max = a[i];
    }
    return max;
}
//�����ַ��䵽���Ե�Ͱ�У�Ȼ����Ͱ��˳�����������
void sort2(int a[], int n, int loop)//���飬Ԫ�أ�λ�� 
{
    //20�Ǽ�����20��Ԫ�أ�10��10���ƣ�0-9��10��Ͱ 
    int buckets[10][20] = {};
    //��Ͱ��index�ĳ���
    //��798��λͰindex=(798/1)%10=8
    //ʮλͰindex=(798/10)%10=9
    //��λͰindex=(798/100)%10=7
    //tempNumΪ��ʽ�е�1��10��100
    int tempNum = (int)pow(10, loop - 1);//loop=1���Ǹ�λ��=2����ʮλ 
    int i, j;
    for(i = 0; i < n; i++)
    {
        int row_index = (a[i] / tempNum) % 10;
        for(j = 0; j < n; j++)
        {
            if(buckets[row_index][j] == 0)//�����ռ�ˣ��ͷŵ�ͬͰ����һ���ط� 
            {
                buckets[row_index][j] = a[i];
                break;
            }
        }
    }
    //��Ͱ�е��������ص�ԭ��������
    int k = 0;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 20; j++)
        {
            if(buckets[i][j] != 0)
            {
                a[k++] = buckets[i][j];
                buckets[i][j] = 0;//���þ��� 
                
            }
        }
    }
}
int main() 
{
 	int a[] = {2, 343, 342, 1, 123, 43, 4343, 433, 687, 654, 3};
    //�������鳤��
    int size = sizeof(a) / sizeof(int);
    //��������
    bucketSort(a, size);
    //��ӡ�������
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

	return 0;
}
