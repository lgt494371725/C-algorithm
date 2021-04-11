//https://blog.csdn.net/codes_first/article/details/78474226 ���ְ˻ʺ�ⷨ 
#include <stdio.h>
#include<string.h> 
//p34 
int count = 0;

int notDanger( int row, int j, int (*chess)[8] )
{
	int i, k, flag1=0, flag2=0, flag3=0, flag4=0, flag5=0;
//��Ϊ���»Ὣ���ж���ʼ�������Բ����ж��� 
	// �жϸ�����û��Σ��  
	for( i=0; i < 8; i++ )
	{
		if( *(*(chess+i)+j) != 0 )
		{
			flag1 = 1;
			break;
		}
	}

	// �ж����Ϸ� 
	for( i=row, k=j; i>=0 && k>=0; i--, k-- )
	{
		if( *(*(chess+i)+k) != 0 )
		{
			flag2 = 1;
			break; 
		}
	}

	// �ж����·� 
	for( i=row, k=j; i<8 && k<8; i++, k++ )
	{
		if( *(*(chess+i)+k) != 0 )
		{
			flag3 = 1;
			break;
		}
	}

	// �ж����Ϸ� 
	for( i=row, k=j; i>=0 && k<8; i--, k++ )
	{
		if( *(*(chess+i)+k) != 0 )
		{
			flag4 = 1;
			break;
		}
	}

	// �ж����·� 
	for( i=row, k=j; i<8 && k>=0; i++, k-- )
	{
		if( *(*(chess+i)+k) != 0 )
		{
			flag5 = 1;
			break;
		}
	}

	if( flag1 || flag2 || flag3 || flag4 || flag5 )//�������κ�һ���лʺ� 
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// row: ��ʼ�� 
// n: �� 
// (*chess)[8]: ָ��ÿһ�� 
void EightQueen( int row, int n, int (*chess)[8] )
{
	int chess2[8][8], i, j;//��ʱ���� 
//��Ҫ���̵����ɣ� 
	for( i=0; i < 8; i++ )
	{
		for( j=0; j < 8; j++ )
		{
			chess2[i][j] = chess[i][j];
		}
	}

	if( 8 == row )
	{
		printf("��%d ��\n", count+1);
		for( i=0; i < 8; i++ )
		{
			for( j=0; j < 8; j++ )
			{
				printf("%d ", *(*(chess2+i)+j));
			}
			printf("\n");
		}
		printf("\n");
		count++;
	}
	else
	{ 
		for( j=0; j < n; j++ )//j���� 
		{
			if( notDanger( row, j, chess ) ) // �ж�λ���Ƿ�Σ�գ�ûΣ������� 
			{
				for( i=0; i < 8; i++ )
				{
					*(*(chess2+row)+i) = 0;//����������λ�ö�Ϊ0���ٴγ�ʼ������ 
				}
//��Ҫ��ʼ�����̵����ɣ���Ϊ�����̵�˳�����ȴ�0��0��ʼ������1��Ȼ�����1��0�����˵ݹ飬�Ȳ��ܵݹ�������ص�ѭ������ʱj=1��
//j=1����ʱ����0��1���жϺ������룬û���ж��У���ʱ0��0λ����1���Ѿ�����ݹ��ˣ�Ҫ��1��ˢ�µ������forѭ�������ң��ݹ�����ϵ��� 
				*(*(chess2+row)+j) = 1;//��ȫλ�÷Żʺ� 

				EightQueen( row+1, n, chess2 );//�õĵݹ飬�����ظ� 
			}
		} 
	}
}

int main()
{
	int chess[8][8], i, j;

	memset(chess,0,sizeof(chess));

	EightQueen( 0, 8, chess );

	printf("�ܹ���%d ����\n\n", count);

	return 0;
}
