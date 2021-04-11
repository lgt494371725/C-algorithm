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
int calc(int (*p)(int,int),int num1,int num2)//(*p)(int,int)表示指向函数的变量数目 ，函数指针 
{
	return (*p)(num1,num2);
}
int(*select(char op))(int,int);
int(*select(char op))(int,int)// 函数指针作为返回值的函数，他的返回值带有两个参数，自己的函数是以char为参数 
{                 //因为运算优先级，先看里面，然后首先确定这是一个函数，带一个字符参数，返回的是一个指针 
	switch(op)
	{
		case'+':return add;
		case'-':return sub;
	}
}
int main()
{
	int num1,num2;
	char op;
	int (*p)(int,int);
	printf("请输入一个式子");
	scanf("%d%c%d",&num1,&op,&num2);
	p=select(op);
	printf("%d %c %d=%d\n",num1,op,num2,calc(p,num1,num2));
	return 0;
}
