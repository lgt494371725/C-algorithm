#include<stdio.h>
void func();
void func()
{
	static int count=0;//������=0�Ļ���static��û��static�����һ���� 
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
