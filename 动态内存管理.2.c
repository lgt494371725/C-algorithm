#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i,num;
	int count=0;
	int *ptr=NULL;//�����ʼ��ΪNULL,����realloc���൱��malloc
	do{
	printf("���������֣�������-1������ֹ¼��");
	scanf("%d",&num);
	count+=1;
	ptr=(int *)realloc(ptr,count*sizeof(int)); //��������ԭ���ڴ� 
	
	ptr[count-1]=num;
	}while(num!=-1);
	for(i=0;i<count-1;i++)
	{
		printf("%d ",ptr[i]);
	}
	free(ptr);//��Ҫ����Ҫ���� 
	return 0;
} 
