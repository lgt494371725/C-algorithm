#include<stdio.h>

int main()
{
	int count=0;
	printf("请输入一行字符；\n");
	while(getchar()!='\n')
	{
		count=count+1;
	}
	printf("您总共输入了%d个字符\n",count);
	return 0;
}
