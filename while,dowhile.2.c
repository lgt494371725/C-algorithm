#include<stdio.h>

int main()
{
	int count=0;
	printf("������һ���ַ���\n");
	while(getchar()!='\n')
	{
		count=count+1;
	}
	printf("���ܹ�������%d���ַ�\n",count);
	return 0;
}
