#include<stdio.h>

void func();
int a,b=630;
void func()
{
	int b;
	a=880;//��Ϊ������δ����a�����a��ȫ�ֱ��� 
	b=120;//bΪ�ֲ��������޷����嵽������ 
	printf("In fun,a=%d,b=%d\n",a,b);
 } 
 int main()
 {
 	printf("in main,a=%d,b=%d\n",a,b);
 	func();
 	printf("in main,a=%d,b=%d",a,b);
 	return 0;
 }
