#include<stdio.h>

int main()
{
	int a;
	int *p=&a;
	
	printf("��������");
	scanf("%d",&a);
	printf("a=%d\n",a);
	printf("��������һ������");
	
	scanf("%d",p);
	printf("a=%d\n",a);

	return 0;
}
