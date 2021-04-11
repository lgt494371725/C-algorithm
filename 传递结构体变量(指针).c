#include<stdio.h>

struct Book
{
	char title[120];
	char author[20];
	float price;	
};
void *getinput(struct Book *book)//因为是结构体，所以类型定义为struct Book 
{
	printf("请输入标题\n");
	scanf("%s",book->title);
	printf("请输入作者\n");
	scanf("%s",book->author);
	printf("请输入价格\n"); 
	scanf("%f",&book->price);

}
int main()
{
	struct Book b1,b2;
	printf("请录入第一本书的信息\n");
	getinput(&b1);
	printf("录入完毕!\n");
	printf("%s\n%s\n%f\n",b1.title,b1.author,b1.price);
	
	return 0;	 
}   
