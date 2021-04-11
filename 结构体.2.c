#include<stdio.h>

struct Book
{
	int number;
	char name[120];
	char author[120];	
} ;
int main()
{
	struct Book book={
	123,"我的青春恋爱物语","渡航" 
	};
	printf("%d\n%s\n%s\n",book.number,book.name,book.author);
	return 0;	 
}   
