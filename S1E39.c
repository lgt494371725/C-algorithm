#include<stdio.h>
void funcA(void)
{
	printf("funca");
}
void funcB(void)
{
	printf("funcb");
}
int main()
{
	void (*array[2])(void);//也可以把这个定义放到函数外面，array是指针数组，数组的每个元素都是函数指针，参数和返回值都是void类型 
	array[0]=funcA;
	array[1]=funcB;
	funcA();
	array[0]();//这里的括号绝对不能丢 
	return 0;
}
