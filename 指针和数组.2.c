#include<stdio.h>
int main()
{
	char a[]={"yukino"};
	char *p=a;  //ʡȥ���У����е�*p,*(p+1),*(p+2)��pȫ��Ϊb��Ч����ͬ 
	printf("*p=%c,*(p+1)=%c,*(p+2)=%c\n",*p,*(p+1),*(p+2));
	return 0;
}
