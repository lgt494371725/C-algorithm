#include<stdio.h>
#define number 5
int main()
{
	int a[number];
	int i,sum=0;	
	for(i=0;i<5;i++)
	{
		printf("请输入第%d位同学的身高",i+1);
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	printf("录入完毕，平均身高是%.2f\n",(double)sum/number);
	
	
	return 0;
 } 
