#include<stdio.h>
int main()
{
	int i;	
	char *love[]={"ħ���Ƹ��е��ӵ���",
					"�ҵ��ഺ�����Ȼ������",
					"������"};
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
