#include <stdio.h>
#include <string.h>

#define HEIGHT 7  // �������ʒ�?�C?�����ꍂ�x�ϐ�7�s

const char *letters[] = {
"\
\########@\
\##      @\
\##      @\
\######  @\
\##      @\
\##      @\
\##      @\
",
"\
\####@\
\ ## @\
\ ## @\
\ ## @\
\ ## @\
\ ## @\
\####@\
",
"\
\ ###### @\
\##    ##@\
\##      @\
\ ###### @\
\      ##@\
\##    ##@\
\ ###### @\
",
"\
\##     ##@\
\##     ##@\
\##     ##@\
\#########@\
\##     ##@\
\##     ##@\
\##     ##@\
",
"\
\ ###### @\
\##    ##@\
\##      @\
\##      @\
\##      @\
\##    ##@\
\ ###### @\
"
};

int main()
{
        int i, j;
        int gap;

        printf("��������ĸ���");
        scanf("%d", &gap);

        // һ��һ�д�ӡ 
        for (i = 0; i < HEIGHT; i++)
        {
        	//��ӡ������ĸĳһ�� 
                for (j = 0; j < 5; j++)
                {
                        // k ���ڵ���ÿһ�е�# 
                        int k = 0;
                        // ���������ĸÿһ���ж��ٸ��ַ� 
                        int len = strlen(letters[j]) / HEIGHT;
                        // ���㵱ǰ��ӡ�ڼ��� 
                        int line = i * len;

                        // @��־���н��� 
                        while (letters[j][line+k] != '@')
                        {
                                putchar(letters[j][line+k]);
                                k++;
                        }

                        // ��ӡ����ո��� 
                        int temp = gap;
                        while (temp--)
                        {
                                putchar(' ');
                        }
                }
                putchar('\n');
        }

        return 0;
}
