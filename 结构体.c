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
	printf("��������ı��");
	scanf("%d",&book.number);
	printf("����������");
	scanf("%s",book.name);
	printf("����������");
	scanf("%s",book.author);
	printf("¼�����");
	printf("%d\n%s\n%s\n",book.number,book.name,book.author);
	return 0;	 
}   
