#include<stdio.h>
typedef char string[100];
int compare(string a,string b)
{
	int i,j;
	while(1)
	{
		
		if(a[i]==b[0])
		{
			break;	
		}
		i++;	
	}
	return i;
}


int main()
{
	int k;
	k=compare("I love Yukino","Yukino");
	printf("�ظ�λ����%d\n",k);

	return 0;
}
