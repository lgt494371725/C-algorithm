#include<stdio.h>
int temp,tempi,tempj;
int i,j;
int cheese_table[8][8];
int queen[8];//��¼�˸��ʺ������  queen��1��=2���ڶ��лʺ��ٵ����� 
int lastqueen=-1;
int solution=0;
int search_line(int i,int j){//��Ѱ��һ����û�ɷŵ�λ��
	for(;j<8;j++)
		if(cheese_table[i][j]==0)
			return j;
	return -1;
}
void set_queen(int i,int j){//�ڿɷŵ�λ���Ϸ��ϻʺ��¼�����������̽��в���
	cheese_table[i][j]=-1;
	queen[i]=j;
	for(temp=0;temp<8;temp++)//�в���
		if(cheese_table[temp][j]!=-1)
			cheese_table[temp][j]++;
	for(temp=0;temp<8;temp++)//�в���
		if(cheese_table[i][temp]!=-1)
			cheese_table[i][temp]++;
	int tempj=j+1;
	for(tempi=i+1;tempi<8&&tempj<8;tempi++)//���϶Խ��߲���
		cheese_table[tempi][tempj++]++;
	tempj=j-1;
	for(tempi=i+1;tempi<8&&tempj>=0;tempi++)//�����Խ��߲���
		cheese_table[tempi][tempj--]++;
	tempj=j+1;
	for(tempi=i-1;tempi>=0&&tempj<8;tempi--)//���϶Խ��߲���
		cheese_table[tempi][tempj++]++;
	tempj=j-1;
	for(tempi=i-1;tempi>=0&&tempj>=0;tempi--)//�����Խ��߲���
		cheese_table[tempi][tempj--]++;
	return;
}
void uptake_queen(int i){
	int j=queen[i];
	for(temp=0;temp<8;temp++)//�в���
		if(cheese_table[temp][j]!=-1)
			cheese_table[temp][j]--;
	for(temp=0;temp<8;temp++)//�в���
		if(cheese_table[i][temp]!=-1)
			cheese_table[i][temp]--;
	int tempj=j+1;
	for(tempi=i+1;tempi<8&&tempj<8;tempi++)//���϶Խ��߲���
		cheese_table[tempi][tempj++]--;
	tempj=j-1;
	for(tempi=i+1;tempi<8&&tempj>=0;tempi++)//�����Խ��߲���
		cheese_table[tempi][tempj--]--;
	tempj=j+1;
	for(tempi=i-1;tempi>=0&&tempj<8;tempi--)//���϶Խ��߲���
		cheese_table[tempi][tempj++]--;
	tempj=j-1;
	for(tempi=i-1;tempi>=0&&tempj>=0;tempi--)//�����Խ��߲���
		cheese_table[tempi][tempj--]--;
	cheese_table[i][j]=0;
	return;
}
int main(){
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			cheese_table[i][j]=0;
	//��ʼ������
	for(i=0;;i++)
	{
	//һ��һ�в���
		j=search_line(i,lastqueen+1);
		if(j==-1)//����i=7���Ҳ���λ���ˣ��������еĻʺ�����lastqueenλ�ü�Ϊ����������Ļʺ���У�֮��ʹ��������п�ʼ 
			{//û�зŻʺ��λ���ˣ���ͷ
			if(i==0)break;//��������λ��
			uptake_queen(i-1);
			lastqueen=queen[i-1];
//����һ�е�queen��λ�ü�¼���������ڻ�ͷ��ʱ������λ��֮��Ѱ�ҿɷ�λ��
			i-=2;//���i=7�������Ϊ5���Զ�+1���ʴӵ��������¿�ʼ�� 
			}
		else{
//�����̶�Ӧλ�÷��ϻʺ󣬶�����ʺ��Ӱ��������в���
			lastqueen=-1;//���� 
			set_queen(i,j);
			if(i==7)
				{ 
				solution++;
				uptake_queen(7);
				lastqueen=j;
				i--;
				}
			}
	}
	printf("%d\n",solution);
	
	return 0;
}

