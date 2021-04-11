//基数排序，桶排序 
#include<math.h>
#include<stdio.h> 	
void bucketSort(int *p, int n); 
void sort2(int *p, int n, int loop); 

//基数排序
void bucketSort(int a[], int n)
{
    //获取数组中的最大数
    int maxNum = findMaxNum(a, n);
    //获取最大数的位数，次数也是再分配的次数。
    int looptimes=0;//获取数字的位数
    int i;
     while(maxNum)
    {
        looptimes++;
        maxNum/= 10;
    }
    //对每一位进行桶分配
    for(i = 1; i <= looptimes; i++)
    {
        sort2(a, n, i);
    }
}
//获取数字的位数

//查询数组中的最大数
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
//将数字分配到各自的桶中，然后按照桶的顺序输出排序结果
void sort2(int a[], int n, int loop)//数组，元素，位数 
{
    //20是假想有20个元素，10是10进制，0-9这10个桶 
    int buckets[10][20] = {};
    //求桶的index的除数
    //如798个位桶index=(798/1)%10=8
    //十位桶index=(798/10)%10=9
    //百位桶index=(798/100)%10=7
    //tempNum为上式中的1、10、100
    int tempNum = (int)pow(10, loop - 1);//loop=1就是个位，=2就是十位 
    int i, j;
    for(i = 0; i < n; i++)
    {
        int row_index = (a[i] / tempNum) % 10;
        for(j = 0; j < n; j++)
        {
            if(buckets[row_index][j] == 0)//如果被占了，就放到同桶的另一个地方 
            {
                buckets[row_index][j] = a[i];
                break;
            }
        }
    }
    //将桶中的数，倒回到原有数组中
    int k = 0;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 20; j++)
        {
            if(buckets[i][j] != 0)
            {
                a[k++] = buckets[i][j];
                buckets[i][j] = 0;//重置矩阵 
                
            }
        }
    }
}
int main() 
{
 	int a[] = {2, 343, 342, 1, 123, 43, 4343, 433, 687, 654, 3};
    //计算数组长度
    int size = sizeof(a) / sizeof(int);
    //基数排序
    bucketSort(a, size);
    //打印排序后结果
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

	return 0;
}
