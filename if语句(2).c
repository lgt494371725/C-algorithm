#include<stdio.h>
int main()
{
	int i;
	printf("输入分数：");
	scanf("%d",&i);
	if(i>=90) 
	{
	 	printf("你的等级：A\n"); 
	}
	else if(i>=80)
	{
		printf("你的等级：B\n");
	}
	else if(i>=70)
	{
		printf("你的等级：C\n");
	}
	return 0;

}

