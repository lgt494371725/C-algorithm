#include<stdio.h>
#define number 5
int main()
{
	int a[number];
	int i,sum=0;	
	for(i=0;i<5;i++)
	{
		printf("�������%dλͬѧ�����",i+1);
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	printf("¼����ϣ�ƽ�������%.2f\n",(double)sum/number);
	
	
	return 0;
 } 
