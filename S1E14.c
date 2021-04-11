#include<stdio.h>
#define start 23
#define every 14
int main()
{
	int i,price;
	printf("请输入您的包裹重量：");
	scanf("%d",&i);
	if(i>23)
	
		price=start+(i-23)*14;
	
	else 
	{
		price=start;
	}
	printf("您的运费需要%d元",price);
			
	return 0;
 } 
