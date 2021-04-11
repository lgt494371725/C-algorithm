#include <stdio.h>
#include <stdlib.h>

#define INCREMENT 10
#define INIT_SIZE INCREMENT

int main(void)
{
        char ch;
        char *num; // 存储整个数据的首地址 
        char *last; // 最近一次迭代的起始地址 
        int limit = 0; // 每次迭代的限制值 
        long times = 1; // 记录重新申请多少次内存 

        num = (char *)malloc(INIT_SIZE);
        if (num == NULL)
        {
                exit(1);
        }

        last = num;

        printf("请输入一串字符");

        while ((ch=getchar()) != '\n')
        {
                last[limit++] = ch;
                if (limit >= INCREMENT)//这里可以画图来理解 
                {
                        int offset = last - num;//起始地址和最近一次迭代的地址之差 
                        num = (char *)realloc(num, INIT_SIZE + INCREMENT * times++);//初始加上每次增加的 
                        last = num; //新申请的地址 ，每次申请出来的num起始位置可能不同 
                        last += offset;//加上地址差 
                        last += INCREMENT;
                        limit = 0;
                }
        }
        last[limit] = '\0';

        printf("你输入的整数是%s\n", num);
		free(num) ;
        return 0;
}
