#include <stdio.h>
#include <string.h>

#define HEIGHT 7  // 崻悩壓柺掕?丆?槩帤曣崅搙嬒惀7峴

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

        printf("请输入字母间隔");
        scanf("%d", &gap);

        // 一行一行打印 
        for (i = 0; i < HEIGHT; i++)
        {
        	//打印所有字母某一行 
                for (j = 0; j < 5; j++)
                {
                        // k 用于迭代每一行的# 
                        int k = 0;
                        // 计算出该字母每一行有多少个字符 
                        int len = strlen(letters[j]) / HEIGHT;
                        // 计算当前打印第几行 
                        int line = i * len;

                        // @标志改行结束 
                        while (letters[j][line+k] != '@')
                        {
                                putchar(letters[j][line+k]);
                                k++;
                        }

                        // 打印间隔空格数 
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
