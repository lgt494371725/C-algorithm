#include<stdio.h>
int main()
{
	int i,days[]={31,28,31,30};
	int y;
	printf("������һ�����");
	scanf("%d",&y);
	days[1]=y%4==0?29:28;
	for(i=0;i<4;i++)
	{
		printf("%d�·���%d��\n",i+1,days[i]);
	}
		printf("sizeof=%d\n",sizeof(days[0]));
	return 0;
}
