#include<stdio.h>
void func();
void func()
{
	static int count=0;//不输入=0的话，static和没有static结果是一样的 
	printf("%d ",count);
	count++;
}
int main()
{
	int i;
	for(i=0;i<10;i++)
	{

		func();
	}
	

	return 0;
}
