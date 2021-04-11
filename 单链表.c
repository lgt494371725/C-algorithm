#include<stdio.h>
#include<stdlib.h>
struct Book
{
	char title[120];// 
	char author[120]; //��Ϣ�� 
	struct Book *next;//������Ľڵ�������ָ����һ���ڵ�  
};
void getinput(struct Book *book)
{
	printf("���������\n");
	scanf("%s",book->title);
	printf("����������\n");
	scanf("%s",book->author);
}
void addBook(struct Book **library)//�������������Ϊ��Ҫ�޸�ָ���ֵ��������ָ��ĵ�ַ��ָ��BOOK�ṹ���ָ���ָ�� 
{
	struct Book *book,*temp;
	book=(struct Book *)malloc(sizeof(struct Book));
	getinput(book);
	if(library!=NULL)
	{
		temp=*library;
		*library=book; 
		book->next=temp;
	}
	else
	{
		*library=book;
		book->next=NULL;
	}
}
void printfLibrary(struct Book  *library)
{
	struct Book *book;
	int count=1;
	book=library;
	while(book!=NULL)
	{
	printf("������%d\n",count);
	printf("����:%s\n",book->title);
	printf("����:%s\n",book->author);
	book=book->next;
	count++;
	}
}
void releaselibrary(struct Book *library)
{
	while (library!=NULL)
	{
		library=library->next;
		free(library);
	}
}
int main()
{ 
	struct	Book *library=NULL;//ͷָ�룬�յĵ������޸�����ָ��  
	addBook(&library);//���ܸ�library������Ҫ�޸ĵ���ָ���ָ�� 
	printfLibrary(library);
	releaselibrary(library);
	return 0;
}
//ͷָ��ָ���һ���ڵ㣬�������Ϣ���Žڵ㣬�൱�������Ԫ�أ�ָ��ָ����һ���ڵ㡣 
