#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
int main()
{
	FILE *fp;
	if((fp=fopen("cun.txt","r"))==NULL)
	{
		fprintf(stderr,"¥ÌŒÛ‘≠“Ú£∫%s",strerror(errno));
		exit(EXIT_FAILURE);
	}
	fclose(fp); 
	return 0; 
}
 
