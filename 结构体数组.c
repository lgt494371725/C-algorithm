#include<stdio.h>

struct Book
{
	char title[120];
	char author[20];
	float price;	
}book[2];

int main()
{
	scanf("%s",book[0].author);
	char b[29]="sdsdfsdf";
	book[1].title=b;
	printf("%s\n",book[1].title);
	printf("%s",book[0].author);
	
	return 0;	 
}   
 
