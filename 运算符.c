#include<stdio.h>
#include<math.h>

int main()
{
	int i,j,k;
	i=1+3;
	j=1+2*3;
	k=1+j+ -1+pow(2,3);  // 3+7+(-1)+8 注释不会计入计算 
	printf("i=%d\n",i);
	printf("j=%d\n",j);
	printf("k=%d\n",k);
	return 0;
}
