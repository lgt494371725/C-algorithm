#include<Stdio.h>
#include<math.h>
#include<string.h>
#define MAX 1024
int main()
{
	int length,aver;
	int i,j;
	char str[MAX];
	scanf("%s",str);
	length=strlen(str);
	aver=sqrt(length);//����
	for(i=0;i<aver;i++)
	{
		for(j=0;j<aver;j++)
		{
			printf("%c",str[aver*i+j]);//���ַ����Զ�ά�ķ�ʽ��� 
		}
	 	printf("\n");
	 } 
	

	return 0;
}
