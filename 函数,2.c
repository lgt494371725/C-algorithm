#include<stdio.h>
int max(int,int);//��������
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
 	printf("��������������\n");
 	scanf("%d%d",&a,&b);
 	c=max(a,b);//a��bΪʵ�ʲ�����x��yΪʵ�ʲ�������ĸ���Բ�ͬ��������Ҫһ�� 
 	printf("�����нϴ��ֵ��%d\n",c);
	 return 0;
 }
