#include <stdio.h>

int main()
{
       	char ch; 

        printf("������һ��Ӣ�ľ���");

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
