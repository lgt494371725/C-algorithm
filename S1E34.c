#include <stdio.h>

void getInput();

void getInput()
{
        int ch;

        if ((ch = getchar()) != '!')
        {
                getInput();
        }
        else
        {
                printf("���������");
        }

        putchar(ch);
}

int main(void)
{
        printf("������һ���Ը�̾�Ž�β��Ӣ�ľ��ӣ�");
        getInput();
        putchar('\n');

        return 0;
}
