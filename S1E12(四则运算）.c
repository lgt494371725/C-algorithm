#include<stdio.h>
int main()
{
	int a,b,j=1;
	char ch;
	float i;
	
	printf("请输入式子");
	scanf("%d %c %d",&a,&ch,&b);
	switch(ch)
	{
		case'+':i=(float)a+b;break;
		case'-':i=(float)a-b;break;
		case'*':i=(float)a*b;break;
		case'/':
		if(b!=0)
		{
			
		i=(float)a/b;break;//强制转换浮点型 
		}
		else{
		printf("除数不能为0");
		}
	}
	if(j==1)
	{
		printf("结果为%f",i);
	}
	else if(j==0)
		{
	printf("除数不能为0");
	}
	
	return 0;

}
