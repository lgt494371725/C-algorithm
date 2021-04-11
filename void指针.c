#include<stdio.h>

int main()
{
	char *ps="yukino";
	void *pv;
	pv=ps;//将pi地址赋给pv
	printf("ps:%p,pv:%p\n",ps,pv);
	printf("pv:%s",(char*)pv);//强制类型转换 ,若是字符串类型则 (char*)pv输出，若是整型 *(int*)pv才能输出，多一个* 

	return 0;
}
