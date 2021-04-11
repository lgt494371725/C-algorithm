#include<stdio.h>
int add(int ,int);
int sub(int,int);
int calc(int(*p)(int,int),int,int);

int add(int num1,int num2)
{
	return num1+num2;
}
int sub(int num1,int num2)
{
	return num1-num2;
}
int calc(int (*p)(int,int),int num1,int num2)//(*p)(int,int)表示指向函数的变量数目 
{
	return (*p)(num1,num2);
}
int main()
{

	
	printf("3+5=%d\n",calc(add,3,5));
	printf("3-5=%d\n",calc(sub,3,5));


	return 0;
}
