#include<stdio.h>

int main()
{

	float fah,cel;//��ע������һ��Ҫһ�� 
	printf("�����뻪�϶�:");
	scanf("%f",&fah);
	cel=(fah-32)*5 / 9; 
	printf("ת��Ϊ���϶��ǣ�%.2f",cel);

	return 0;
}
