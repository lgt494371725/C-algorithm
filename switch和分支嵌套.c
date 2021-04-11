#include<stdio.h>
int main()
{
	char ch;
	printf("请输入成绩:");
	scanf("%c",&ch);
	
	switch (ch)
	{
			case'a':printf("你的成绩在90分以上！\n");break;
			case'b':printf("你的成绩在80分以上！\n");break;
			case'c':printf("你的成绩在70分以上！\n");break;
			case'd':printf("你的成绩在60分以上！\n");break;
			default:printf("请输入有效字母\n");
	} 
	return 0;
}
