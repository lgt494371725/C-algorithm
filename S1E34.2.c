#include<stdio.h>

void binary(unsigned long u);
void binary(unsigned long u)
{
	int r;
	r=u%2;
	if(u>=2)
	{
		binary(u/2);
	}
	printf("%d",r);
}
int main()
{
	unsigned long number;
	printf("请输入一个正整数");
	scanf("%lu",&number);
	binary(number);
	return 0;
}
