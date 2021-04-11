#include<stdio.h>

struct Book
{
	int number;
	char name[120];
	char author[120];	
} ;
int main()
{
	struct Book book;
	printf("请输入书的编号");
	scanf("%d",&book.number);
	printf("请输入书名");
	scanf("%s",book.name);
	printf("请输入作者");
	scanf("%s",book.author);
	printf("录入完毕");
	printf("%d\n%s\n%s\n",book.number,book.name,book.author);
	return 0;	 
}   
