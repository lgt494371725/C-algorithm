#include<stdio.h>
#include<string.h>//memset函数需要用

int main()
{
	char buff[1024];
	memset(buff,'\0',sizeof(buff));
	setvbuf(stdout,buff,_IOFBF,1024);//按块缓存 
	fprintf(stdout,"welcome\n");
    fflush(stdout);//刷新缓冲区，将缓冲区数据即刻输入指定文件，如果没有这一行，
	//welcome也不会显示，只有在getchar（）输入后才会出现 
	getchar();//他的位置在中间还是末尾都一样 
	fprintf(stdout,"输入任意字符后才会显示\n");

	return 0;
 } 
