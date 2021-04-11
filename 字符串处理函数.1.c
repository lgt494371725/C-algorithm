#include<stdio.h>
#include<string.h>

int main()
{
	char str[]="I love FishC.com!";
	printf("size of str=%d\n",sizeof(str)); //sizeof计算长度包括一个终止符‘、0’ 
	printf("strlen str=%u\n",strlen(str));//不包括终止符 
	return 0;
 } 
