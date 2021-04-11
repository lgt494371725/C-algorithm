#include<stdio.h>
#include<stdlib.h>
 
typedef struct Date
{
	int year;
	int month;
	int day;
}DATE;

int main()
{
	struct Date *date;
	date=(DATE *)malloc(sizeof(DATE));
	date->year=2008;
	date->month= 8;
	date->day=28;
	printf("%d-%d-%d",date->year,date->month,date->day);
	return 0;	 
}   
