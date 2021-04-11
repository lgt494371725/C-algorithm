#include <stdio.h>
#define INF 255
#define MAXN 16

int Len[MAXN];  int Prev[MAXN]; 
int allvisited(int *a,int n){
	int i,r=1;
	for(i=0;i<n;i++){r*=a[i];}
	return r; 
}
void printpath(int v){
	if(v!=-1){
		printpath(Prev[v]);printf("-%d",v);
	}
}
void compute(int *w,int n,int s,int d){
	int i,j,next,min,visited[MAXN];
	for(i=0;i<n;i++)
	{
		Len[i]=INF;visited[i]=0;Prev[i]=-1;
	 } 
	 i=s;Len[i]=0;visited[i]=1;
	 while(allvisited(visited,n)==0){
	 	min=INF;next=d;
	 	for(j=0;j<n;j++){
	 		if(visited[j]==1) continue;
	 		if(Len[j]>Len[i]+w[i*n+j]){
	 			Len[j]=Len[i]+w[i*n+j];	Prev[j]=i;
			 }
			 if(min>Len[j]){
			 	min=Len[j];next=j;
			 }
		 }
		 i=next;visited[i]=1;
	 }
}
int main()
{
	int w[]={0,2,5,INF,
	         2,0,1,1,
			 5,1,0,2,
			 INF,1,2,0};
	int n=4 ;
	compute(w,n,0,3);
	printf("path length from 0to3 is %d\n",Len[3]);
	printpath(3); printf("\n");
	return 0;
}























