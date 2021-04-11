#include <stdio.h>

int a[1024]; 

void printa(int n){
	int i;
	if(n>0) printf("%d",a[0]);
	for(i=1;i<n;i++)
	printf(",%d",a[i]);
	printf("\n");
}

int check(int x,int y)
{
	int k;
	for(k=0;k<x;k++){
		if(a[k]==y)
		return 0;
	}
	return 1;
}
void f(int n,int x){
	if(x>=n){
		printa(n);}
	else{
		int y=0;
		while(y<n){
			if(check(x,y)){
				a[x]=y;
				f(n,x+1);
			}
			y=y+1;
		}
	}
}
int main()
{
	f(4,0);
	return 0;
}
