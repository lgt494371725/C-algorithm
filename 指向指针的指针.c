#include<stdio.h>
int main()
{
	int i;	
	char *love[]={"魔法科高中的劣等生",
					"我的青春物语果然有问题",
					"海贼王"};
	char **favorate=&love[2];//
	char **like[2];
	like[0]=&love[0];
	like[1]=&love[1];
	for(i=0;i<2;i++)
	{	printf("%s\n",*like[i]);


	}
	printf("%s",*favorate);

	return 0;
}
