#include<stdio.h>
#include<string.h>

int main()
{
	char str1[]="1,2,3";
	char str2[]="1,2,3";
	
	if(!strcmp(str1,str2))
	{
		printf("��ȫһ��");
	}
	else
	{
		printf("��һ��"); 
		}	
	return 0;
}
