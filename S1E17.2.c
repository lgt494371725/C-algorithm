#include<stdio.h>
int main()
{
	int year1,year2,month1,month2,day1,day2,i;
	int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
	long long count=0;
	printf("请输入你的生日（如1988-05-20）：");
    scanf("%d %d %d", &year1, &month1, &day1);
	printf("请输入今年日期（如2016-03-28）：");
    scanf("%d %d %d", &year2, &month2, &day2);
    while(year1<=year2)
    {
    days[1]=(year1%4==0)?29:28;
		while(month1<=12)
		{
				while(day1<=days[month1-1])
				{
					
						if(year1==year2&&month1==month2&&day1==day2)
						{
							goto END;
						}
				
					day1++;
					count++;
					
				}
			day1=1;
			month1++;
		} 
		month1=1;
		year1++; 
	}
END:printf("你已经活了%d天",count);
	return 0;
}
