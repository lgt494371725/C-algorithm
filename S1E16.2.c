#include <stdio.h>

int main()
{
        double awards = 4000000;
        int count = 0;

        while (awards >= 0)
        {
                awards -= 500000;
                awards = awards * 1.08;
                count++;
        }

        printf("%d��֮��Ǯ������\n", count);

        return 0;
}
