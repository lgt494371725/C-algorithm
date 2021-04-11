#include<stdio.h>

int main()
{
	int a;
	char b;
	float c;
	double d;
	
	a=520;
	b='F'; 
	c=3.14; 
	d=3.1415926; 
	printf("他最想说的话是%d\n",a);
	printf("%cantistics\n",b);
	printf("圆周率是:%.2f\n",c);
	printf("精确到小数点后7位是:%9.7f\n",d);
	
	return 0;
}
