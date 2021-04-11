#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp1;
	FILE *fp2;
	int ch;
	if((fp1=fopen("hello.txt","r"))==NULL)
	{
		printf("文件读取失败");
		exit(EXIT_FAILURE);
	}
	if((fp2=fopen("yukino.txt","w"))==NULL)
	{
		printf("文件读取失败");
		exit(EXIT_FAILURE);
	}
	while((ch=fgetc(fp1))!=EOF)
	{
		fputc(ch,fp2);
	}//此时fp1内的文件已经写入了fp2 
	fclose(fp1);
	fclose(fp2);
	return 0;
}
