#include<stdio.h>

struct Date
{
	int year;
	int month;
	int day;	
};

struct Book
{
	int number;
	char name[120];
	struct Date date;
	char author[120];	
} ;
int main()
{
	struct Book book={
	123,"�ҵ��ഺ��������",{2019,11,19},"�ɺ�" 
	};
	printf("%d\n%s\n%d\n%s\n",book.number,book.name,book.date.year,book.author);
	
	return 0;	 
}   
