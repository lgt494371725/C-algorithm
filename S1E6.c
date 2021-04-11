#include <stdio.h>
#include <math.h>

int main()
{
        unsigned long long sum = 0;
        unsigned long long temp;
        unsigned long long weight;
        int i;

        for (i=0; i < 64; i++)
        {
                temp = pow(2, i);//如果省去temp，结果就会出错 
                sum = sum + temp;
        }

        weight = sum / 25000;

        printf("舍罕王应该给予达依尔%llu粒麦子！\n", sum);//注意llu 
        printf("如果每25000粒麦子为1kg，那么应该给%llu公斤麦子！\n", weight);

        return 0;
}
