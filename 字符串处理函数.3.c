#include<stdio.h>
#include<string.h>

int main()
{
	char str1[]="original string";
	char str2[]="2nd string";
	char str3[100];
	strcpy(str1,str2);//str1的空间必须能够容纳str2 
	strcpy(str3,"copy successfully");
	printf("str1=%s\n",str1);
	printf("str2=%s\n",str2);
	printf("str3=%s\n",str3);

	return 0;
 } 
 
