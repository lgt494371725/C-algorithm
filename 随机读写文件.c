#include<stdio.h>
#include<stdlib.h>
#define N 4
struct Stu
{
	char name[120];
	int num;
	float score;
}stu[N],sb;
int main(void)
{
	FILE *fp;
	int i;
	if((fp=fopen("score.txt","wb"))==NULL)
	{	
		printf("文件打开失败");
		exit(EXIT_FAILURE);
	}
	printf("请开始录入成绩");
	for(i=0;i<N;i++)
	{
		scanf("%s %d %f",stu[i].name,&stu[i].num,&stu[i].score);
	}
	fwrite(stu,sizeof(struct Stu),N,fp);
	fclose(fp);
	if((fp=fopen("score.txt","rb"))==NULL)
	{	
		printf("文件打开失败");
		exit(EXIT_FAILURE);
	}
	fseek(fp,sizeof(struct Stu),SEEK_SET);
	fread(&sb,sizeof(struct Stu),1,fp);
	printf("%s:%d的成绩是%f",sb.name,sb.num,sb.score);
	fclose(fp);
	return 0;
}
