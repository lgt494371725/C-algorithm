#include <stdio.h>

int main()
{
       	char ch; 
		int count = 0;

        printf("������һ��Ӣ�ľ���");

        while ((ch = getchar()) != '\n')  
        {
                if (ch >= 'A' && ch <= 'Z')//�������־Ͱ�A��Z��Ϊ0��9 
                {
                        count = count + 1;
                }
        }

        printf("���ܹ�������%d����д��ĸ\n", count);

        return 0;
}
