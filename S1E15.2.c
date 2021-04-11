#include <stdio.h>

int main()
{
        int count = 2;
        int i, j;
        _Bool flag = 1;

        for (i = 5; i < 10; i++)
        {
                for (j = 2; j < i / 2; j++)
                {
                        if (i % j == 0)
                        {
                                flag = 0;
                                break;
                        }
                }

                if (flag)
                {
                        count++;
                }
                else
                {
                        flag = 1;
                }
        }

        printf("10000以内%d个素数\n", count);

        return 0;
	}
