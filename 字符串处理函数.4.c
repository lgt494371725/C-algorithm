#include<stdio.h>
#include<string.h>

int main()
{
	char str1[]="1,2,3";
	char str2[]="1,2,3";
	
	if(!strcmp(str1,str2))
	{
		printf("完全一致");
	}
	else
	{
		printf("不一致"); 
		}	
	return 0;
}
