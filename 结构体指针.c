#include<stdio.h>

struct Date
{
	int year;
	int month;
	int day;	
}date={2019,11,25};


int main()
{
	struct Date *pt;
	pt=&date;
	printf("%d\n",*pt.year);
	printf("%d",pt->month);
	
	return 0;	 
}   
