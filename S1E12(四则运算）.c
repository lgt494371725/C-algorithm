#include<stdio.h>
int main()
{
	int a,b,j=1;
	char ch;
	float i;
	
	printf("������ʽ��");
	scanf("%d %c %d",&a,&ch,&b);
	switch(ch)
	{
		case'+':i=(float)a+b;break;
		case'-':i=(float)a-b;break;
		case'*':i=(float)a*b;break;
		case'/':
		if(b!=0)
		{
			
		i=(float)a/b;break;//ǿ��ת�������� 
		}
		else{
		printf("��������Ϊ0");
		}
	}
	if(j==1)
	{
		printf("���Ϊ%f",i);
	}
	else if(j==0)
		{
	printf("��������Ϊ0");
	}
	
	return 0;

}
