#include<stdio.h>
int main()
{
	char a[]={"yukino"};
	char *p=a;  //省去这行，下行的*p,*(p+1),*(p+2)的p全改为b，效果相同 
	printf("*p=%c,*(p+1)=%c,*(p+2)=%c\n",*p,*(p+1),*(p+2));
	return 0;
}
