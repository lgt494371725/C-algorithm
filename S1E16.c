#include<stdio.h>
#include<math.h>

int main()
{
	int jiayu,heiye,year=1;
	jiayu=heiye=10000;
	
	while(heiye<=jiayu)
	{
		year+=1;
	jiayu=10000+year*1000;
	heiye=10000*pow(1.05,year);
	}
	printf("%d\n",year);
	printf("%d",heiye);
	return 0;
}
