#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Book
{
	char name[120];
	char author[120];
		
};
int main()
{
	FILE *fp;
	struct Book *write,*read;
	write=(struct Book*)malloc(sizeof(struct Book));
	
	strcpy(write->name,"�ҵ��ഺ���������Ȼ������");
	strcpy(write->author,"�ɺ�");
	if((fp=fopen("file.txt","w"))==NULL)
	{
		printf("�ļ���ȡʧ��");
		exit(EXIT_FAILURE);
	}
	fwrite(write,sizeof(struct Book),1,fp);
	fclose(fp);
	if((fp=fopen("file.txt","w"))==NULL)
	{
		printf("�ļ���ȡʧ��");
		exit(EXIT_FAILURE);
	}
	fread(read,sizeof(struct Book),1,fp);
	printf("%s\n %s\n",read->name);
	fclose(fp);
	return 0;
}

