#include<stdio.h>
int main()
{
	char slogan[5][100];
	char ch;
	int i,j;
	for(i=0;i<5;i++)
	{
		printf("ÇëÊäÈëµÚ%d¾ä»°\n",i+1);
		for (j = 0; (ch = getchar()) != '\n'; j++)
                {
                        slogan[i][j] = ch;
                }
	}  
	for(i=0;i<5;i++)
	{
		printf("%s\n",slogan[i]);
	}

	return 0;
}
