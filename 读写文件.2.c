#include<stdio.h>
#include<stdlib.h>
#define MAX 1024
int main()
{
	FILE *fp;
	int ch;
	char buffer[MAX];
	if((fp=fopen("lines.txt","w"))==NULL)
	{
		printf("�ļ���ȡʧ��");
		exit(EXIT_FAILURE);
	}
	fputs("Line one:hikigaya\n",fp);
	fputs("Line two:yukino\n",fp);
	fputs("Line three:syouri\n",fp);
	fclose(fp);//д��д���������д��ر��ļ�������ٿ� 
	if((fp=fopen("lines.txt","r"))==NULL)
	{
		printf("�ļ���ȡʧ��");
		exit(EXIT_FAILURE);
	}
	while(!feof(fp))//��feof���жϣ����ĩβָʾ�������ˣ����ط�0ֵ 
	{
		fgets(buffer,MAX,fp);
		printf("%s",buffer);
	}
	fclose(fp);
	return 0;
}
