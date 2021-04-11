#include <stdio.h>

int main()
{
       	char ch; 
		int count = 0;

        printf("请输入一行英文句子");

        while ((ch = getchar()) != '\n')  
        {
                if (ch >= 'A' && ch <= 'Z')//计算数字就把A和Z改为0和9 
                {
                        count = count + 1;
                }
        }

        printf("你总共输入了%d个大写字母\n", count);

        return 0;
}
