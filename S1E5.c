#include<stdio.h>
#define PI 3.1415926
#define s(r) PI*r*r
#define C(r) 2*PI*r

int main() 
{
	int r=5;
	printf("半径%d的圆,面积是%.2f,周长是%.2f",r,s(r),C(r));
	return 0;
}
