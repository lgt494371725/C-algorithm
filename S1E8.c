#include<stdio.h>

int main()
{

	float fah,cel;//请注意类型一定要一致 
	printf("请输入华氏度:");
	scanf("%f",&fah);
	cel=(fah-32)*5 / 9; 
	printf("转换为摄氏度是：%.2f",cel);

	return 0;
}
