#include<stdio.h>
#include<string.h>

int main()
{
	char str1[]="I love";
	char str2[]="Yukinoshita";
	strncat(str1,str2,11);
	printf("str1:%s\n",str1);
	return 0;
}
