#include <stdio.h>

int main()
{
       	char ch; 

        printf("请输入一行英文句子");

        while ((ch = getchar()) != '\n')  
        {
                if (ch >= 'A' && ch <= 'Z')
                {
                        ch=ch+32;
                }
        	
				putchar(ch);
		}

       

        return 0;
}
