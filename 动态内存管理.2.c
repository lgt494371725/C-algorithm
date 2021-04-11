#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i,num;
	int count=0;
	int *ptr=NULL;//必须初始化为NULL,这样realloc会相当于malloc
	do{
	printf("请输入数字，当输入-1程序终止录入");
	scanf("%d",&num);
	count+=1;
	ptr=(int *)realloc(ptr,count*sizeof(int)); //不断扩大原有内存 
	
	ptr[count-1]=num;
	}while(num!=-1);
	for(i=0;i<count-1;i++)
	{
		printf("%d ",ptr[i]);
	}
	free(ptr);//重要，不要忘记 
	return 0;
} 
