#include<stdio.h>
int main()
{
	printf("%c%c%c%c%c\n",70,105,115,104,67);
	printf("%8d\n",2015);//8d占四个字符
	printf("%010d\n",2015);//把第一个0换成其他的只会增加空格
	printf("%10.2f\n",3.1415);
	printf("%-10.2f\n",3.1415) ;//左对齐 
	printf("右对齐，指数形式：%E\n",52000000.0);//数一定要加小数点，e可写成E（大写） 
	return 0;
 } 
