#include<stdio.h>
int main()
{
	char slogan[5][100];
	char ch;
	int i,j;
	for(i=0;i<5;i++)
	{
		printf("�������%d�仰\n",i+1);
		j=0;//һ��Ҫ����j=0�������������� 
		while((ch=getchar())!='\n')
      {
       slogan[i][j++] = ch;
     }
	}  
	for(i=0;i<5;i++)
	{
		printf("%s\n",slogan[i]);
	}

	return 0;
}
