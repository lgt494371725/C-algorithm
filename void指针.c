#include<stdio.h>

int main()
{
	char *ps="yukino";
	void *pv;
	pv=ps;//��pi��ַ����pv
	printf("ps:%p,pv:%p\n",ps,pv);
	printf("pv:%s",(char*)pv);//ǿ������ת�� ,�����ַ��������� (char*)pv������������� *(int*)pv�����������һ��* 

	return 0;
}
