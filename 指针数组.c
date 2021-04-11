#include<stdio.h>

int main()
{
	char *p1[3]={"yukinoshita","hikigaya","yuigahama"};//数组的char p1[]只能跟一行”yukinoshita“ 
	int i;
	for(i=0;i<3;i++)
	{
		printf("%s\n",p1[i]);//不需要输入* 
	}

	return 0;
}
