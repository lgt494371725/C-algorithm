#include<stdio.h>

int main()
{
	char a;
	printf("������һ���ַ���");
	scanf("%c",&a);
	if (a>='A'&&a<='Z')
	{
		a=a+32;
	}
	else if(a>='a'&&a<='z')
	{
		a=a-32;
	}
	printf("%c\n",a);
	return 0;
}

