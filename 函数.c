#include<stdio.h>

int sum(int n);
int sum(int n)//��Ҫ������ ,�������intȥ��������� 
{
	int result=0;
	do
	{
	result+=n;
	}while(n-->0);
	return 0;
}
int main()
{
	int n,result;
	printf("������n��ֵ��");
	scanf("%d",&n);
	result=sum(n);
	printf("1+2+3+xxx+n�Ľ���ǣ�%d\n",result);
	return 0;	
}
