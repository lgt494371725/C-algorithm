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
		printf("文件读取失败");
		exit(EXIT_FAILURE);
	}
	fputs("Line one:hikigaya\n",fp);
	fputs("Line two:yukino\n",fp);
	fputs("Line three:syouri\n",fp);
	fclose(fp);//写归写，读归读，写完关闭文件，随后再开 
	if((fp=fopen("lines.txt","r"))==NULL)
	{
		printf("文件读取失败");
		exit(EXIT_FAILURE);
	}
	while(!feof(fp))//用feof来判断，如果末尾指示器设置了，返回非0值 
	{
		fgets(buffer,MAX,fp);
		printf("%s",buffer);
	}
	fclose(fp);
	return 0;
}
