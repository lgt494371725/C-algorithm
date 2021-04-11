#include<stdio.h>
#include<stdlib.h>
struct Book
{
	char title[120];// 
	char author[120]; //信息域 
	struct Book *next;//单链表的节点声明，指向下一个节点  
};
void getinput(struct Book *book)
{
	printf("请输入标题\n");
	scanf("%s",book->title);
	printf("请输入作者\n");
	scanf("%s",book->author);
}
void addBook(struct Book **library)//两层解引用是因为需要修改指针的值，传的是指针的地址，指向BOOK结构体的指针的指针 
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
	printf("数量：%d\n",count);
	printf("书名:%s\n",book->title);
	printf("作者:%s\n",book->author);
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
	struct	Book *library=NULL;//头指针，空的单链表。修改他的指向  
	addBook(&library);//不能给library，我们要修改的是指针的指向 
	printfLibrary(library);
	releaselibrary(library);
	return 0;
}
//头指针指向第一个节点，链表的信息域存放节点，相当于数组的元素，指针指向下一个节点。 
