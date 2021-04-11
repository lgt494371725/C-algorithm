#include <stdio.h>

int main()
{
        char ch;
        int a, e, i, o, u;

        a = 0;
        e = 0;
        i = 0;
        o = 0;
        u = 0;

        printf("请输入英文句子");

        while ((ch = getchar()) != '\n')
        {
                switch (ch)
                {
                        case 'a':
                        case 'A': a++;
                                  break;
                        case 'e':
                        case 'E': e++;
                                  break;
                        case 'i':
                        case 'I': i++;
                                  break;
                        case 'o':
                        case 'O': o++;
                                  break;
                        case 'u':
                        case 'U': u++;
                                  break;
                }
        }

        printf("输入的句子中含元音字母%d个\n", a + e + i + o + u);
        printf("其中:a(%d),e(%d),i(%d),o(%d),u(%d)\n", a, e, i, o, u);

        return 0;
}
