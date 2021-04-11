#include<stdio.h>
#include<math.h>
int main()
{
	int num,i,j,sum=0;
	
	printf("请输入一个整数\n");
	scanf("%d",&num);
	int cube=pow(num,3);
	for(i=1;i<cube;i+=2)
	{
		for(j=i;j<cube;j+=2)
		{
			sum+=j;
			if(sum==cube)
			{
				printf("%d=%d+%d+%d",cube,i,i+2,j);
				goto END;
			}
			if(sum>cube)
			{
				sum=0;
				break;
			}
		}
		
	}
END:
	
	return 0;
 } 
