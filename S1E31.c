#include<stdio.h>

void func();
int a,b=630;
void func()
{
	int b;
	a=880;//因为函数内未定义a，这个a是全局变量 
	b=120;//b为局部变量，无法定义到函数外 
	printf("In fun,a=%d,b=%d\n",a,b);
 } 
 int main()
 {
 	printf("in main,a=%d,b=%d\n",a,b);
 	func();
 	printf("in main,a=%d,b=%d",a,b);
 	return 0;
 }
