#include<stdio.h>
typedef int *(*PTR_TO_FUN)(int);//һ������ָ�룬��ָ��ָ�뺯�� 
//*PTR_to FUNָ������, *(*PTR_to FUN)(int)ָ�뺯��
//�������3��ָ�뺯�������� 
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

