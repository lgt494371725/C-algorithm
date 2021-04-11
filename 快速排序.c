#include<stdio.h>
void quick_sort(int array[],int left,int right);//这里array加上括号 ，别忘记int array,确定数组类型 
void quick_sort(int array[],int left,int right)
{
	int i,j,mid,k;
	i=left,j=right;
	int temp;
	mid=array[(left+right)/2];//寻找到这个基点，一轮过完以后，基点位置可能会变化
	while(i<=j)
	{
		while(array[i]<mid)
		{
			i++;
		}
		while(array[j]>mid)
		{
			j--;
		}
		if(i<=j)
		{
		temp=array[i];
		array[i]=array[j];
		array[j]=temp;
		i++;
		j--;
		}
	}for(k=0;k<9;k++)
	{
		printf("%d ",array[k]);
	}printf("\n");
	if(left<j)
	{
		quick_sort(array,left,j);
	}
	if(i<right)//如果i大于right，说明所有数都比基点小 
	{
		quick_sort(array,i,right);
	}
} 
int main()
{
	int array[9]={1,2,3,4,22,54,5,64,0};
	int i,length;
	length=sizeof(array)/sizeof(array[0]);
	quick_sort(array,0,length-1);//这里array不要加括号 
	printf("排序后的结果是");
	for(i=0;i<length;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
	
}
