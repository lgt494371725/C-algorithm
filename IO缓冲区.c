#include<stdio.h>
#include<string.h>//memset������Ҫ��

int main()
{
	char buff[1024];
	memset(buff,'\0',sizeof(buff));
	setvbuf(stdout,buff,_IOFBF,1024);//���黺�� 
	fprintf(stdout,"welcome\n");
    fflush(stdout);//ˢ�»������������������ݼ�������ָ���ļ������û����һ�У�
	//welcomeҲ������ʾ��ֻ����getchar���������Ż���� 
	getchar();//����λ�����м仹��ĩβ��һ�� 
	fprintf(stdout,"���������ַ���Ż���ʾ\n");

	return 0;
 } 
