#include<stdio.h>
void quick_sort(int array[],int left,int right);//����array�������� ��������int array,ȷ���������� 
void quick_sort(int array[],int left,int right)
{
	int i,j,mid,k;
	i=left,j=right;
	int temp;
	mid=array[(left+right)/2];//Ѱ�ҵ�������㣬һ�ֹ����Ժ󣬻���λ�ÿ��ܻ�仯
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
	if(i<right)//���i����right��˵�����������Ȼ���С 
	{
		quick_sort(array,i,right);
	}
} 
int main()
{
	int array[9]={1,2,3,4,22,54,5,64,0};
	int i,length;
	length=sizeof(array)/sizeof(array[0]);
	quick_sort(array,0,length-1);//����array��Ҫ������ 
	printf("�����Ľ����");
	for(i=0;i<length;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	return 0;
	
}
