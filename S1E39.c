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
	void (*array[2])(void);//Ҳ���԰��������ŵ��������棬array��ָ�����飬�����ÿ��Ԫ�ض��Ǻ���ָ�룬�����ͷ���ֵ����void���� 
	array[0]=funcA;
	array[1]=funcB;
	funcA();
	array[0]();//��������ž��Բ��ܶ� 
	return 0;
}
