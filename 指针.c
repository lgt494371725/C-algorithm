#include<stdio.h>
int main()
{
	char str[]="love";
	int b=520;
	int *pb=&b;
	char *p=str;
	
	
	printf("%s\n",*p);
	printf("%d\n",*pb);
	return 0;
}
