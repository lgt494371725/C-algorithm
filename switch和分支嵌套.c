#include<stdio.h>
int main()
{
	char ch;
	printf("������ɼ�:");
	scanf("%c",&ch);
	
	switch (ch)
	{
			case'a':printf("��ĳɼ���90�����ϣ�\n");break;
			case'b':printf("��ĳɼ���80�����ϣ�\n");break;
			case'c':printf("��ĳɼ���70�����ϣ�\n");break;
			case'd':printf("��ĳɼ���60�����ϣ�\n");break;
			default:printf("��������Ч��ĸ\n");
	} 
	return 0;
}
