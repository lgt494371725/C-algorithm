#include<stdio.h>

int main()
{
	char *p1[3]={"yukinoshita","hikigaya","yuigahama"};//�����char p1[]ֻ�ܸ�һ�С�yukinoshita�� 
	int i;
	for(i=0;i<3;i++)
	{
		printf("%s\n",p1[i]);//����Ҫ����* 
	}

	return 0;
}
