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
int calc(int (*p)(int,int),int num1,int num2)//(*p)(int,int)��ʾָ�����ı�����Ŀ ������ָ�� 
{
	return (*p)(num1,num2);
}
int(*select(char op))(int,int);
int(*select(char op))(int,int)// ����ָ����Ϊ����ֵ�ĺ��������ķ���ֵ���������������Լ��ĺ�������charΪ���� 
{                 //��Ϊ�������ȼ����ȿ����棬Ȼ������ȷ������һ����������һ���ַ����������ص���һ��ָ�� 
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
	printf("������һ��ʽ��");
	scanf("%d%c%d",&num1,&op,&num2);
	p=select(op);
	printf("%d %c %d=%d\n",num1,op,num2,calc(p,num1,num2));
	return 0;
}
