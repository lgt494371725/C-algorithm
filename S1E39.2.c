#include <stdio.h>
#include <stdlib.h>

#define INCREMENT 10
#define INIT_SIZE INCREMENT

int main(void)
{
        char ch;
        char *num; // �洢�������ݵ��׵�ַ 
        char *last; // ���һ�ε�������ʼ��ַ 
        int limit = 0; // ÿ�ε���������ֵ 
        long times = 1; // ��¼����������ٴ��ڴ� 

        num = (char *)malloc(INIT_SIZE);
        if (num == NULL)
        {
                exit(1);
        }

        last = num;

        printf("������һ���ַ�");

        while ((ch=getchar()) != '\n')
        {
                last[limit++] = ch;
                if (limit >= INCREMENT)//������Ի�ͼ����� 
                {
                        int offset = last - num;//��ʼ��ַ�����һ�ε����ĵ�ַ֮�� 
                        num = (char *)realloc(num, INIT_SIZE + INCREMENT * times++);//��ʼ����ÿ�����ӵ� 
                        last = num; //������ĵ�ַ ��ÿ�����������num��ʼλ�ÿ��ܲ�ͬ 
                        last += offset;//���ϵ�ַ�� 
                        last += INCREMENT;
                        limit = 0;
                }
        }
        last[limit] = '\0';

        printf("�������������%s\n", num);
		free(num) ;
        return 0;
}
