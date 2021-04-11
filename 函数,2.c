#include<stdio.h>
int max(int,int);//定义类型
int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
 } 
 int main()
 {
 	int a,b,c;
 	printf("请输入两个整数\n");
 	scanf("%d%d",&a,&b);
 	c=max(a,b);//a，b为实际参数，x，y为实际参数，字母可以不同，但类型要一致 
 	printf("他们中较大的值是%d\n",c);
	 return 0;
 }
