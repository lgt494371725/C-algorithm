#include<stdio.h>

struct Book
{
	char title[120];
	char author[20];
	float price;	
};
void *getinput(struct Book *book)//��Ϊ�ǽṹ�壬�������Ͷ���Ϊstruct Book 
{
	printf("���������\n");
	scanf("%s",book->title);
	printf("����������\n");
	scanf("%s",book->author);
	printf("������۸�\n"); 
	scanf("%f",&book->price);

}
int main()
{
	struct Book b1,b2;
	printf("��¼���һ�������Ϣ\n");
	getinput(&b1);
	printf("¼�����!\n");
	printf("%s\n%s\n%f\n",b1.title,b1.author,b1.price);
	
	return 0;	 
}   
