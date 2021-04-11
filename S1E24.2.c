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
	aver=sqrt(length);//根号
	for(i=0;i<aver;i++)
	{
		for(j=0;j<aver;j++)
		{
			printf("%c",str[aver*i+j]);//将字符串以二维的方式输出 
		}
	 	printf("\n");
	 } 
	

	return 0;
}
