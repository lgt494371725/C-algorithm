#include<stdio.h>
#include<math.h>
int main()
{
	float plan1,plan2,plan3;
	int cost=10000;
	float r1=0.0175,r2=0.0225,r3=0.0275,r5=0.0275;
	plan1=cost*(1+r5*5);
	plan2=cost*(1+r2*2)*(1+r3*3);
	plan3=cost*pow((1+r1),5);
	printf("%.2f\n",plan1);
		printf("%.2f\n",plan2);
		printf("%.2f\n",plan3);
	return 0;
}
