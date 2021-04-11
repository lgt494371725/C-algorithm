#include<stdio.h>
typedef int *(*PTR_TO_FUN)(int);//一个整型指针，且指向指针函数 
//*PTR_to FUN指针数组, *(*PTR_to FUN)(int)指针函数
//即存放着3个指针函数的数组 
int *funA(int num)
{
	printf("%d",num);
	return &num;	
} 
int *funB(int num)
{
	printf("%d",num);
	return &num;	
} 
int *funC(int num)
{
	printf("%d",num);
	return &num;	
} 
int main(void)
{
	PTR_TO_FUN array[3]={&funA,&funB,&funC};
	int i;
	for(i=0;i<3;i++)
	{
		printf("addr of num=%p\n",(*array[i])(i));
	}
	return 0; 
}

