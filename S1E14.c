#include<stdio.h>
#define start 23
#define every 14
int main()
{
	int i,price;
	printf("���������İ���������");
	scanf("%d",&i);
	if(i>23)
	
		price=start+(i-23)*14;
	
	else 
	{
		price=start;
	}
	printf("�����˷���Ҫ%dԪ",price);
			
	return 0;
 } 
