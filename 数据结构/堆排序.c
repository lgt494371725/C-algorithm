//https://blog.csdn.net/u013384984/article/details/79496052
#include <stdio.h>

int count = 0;

void swap(int k[], int i, int j)
{
	int temp;

	temp = k[i];
	k[i] = k[j];
	k[j] = temp;
}

void HeapAdjust(int k[], int s, int n)
{
	int i, temp;

	temp = k[s];//双亲节点 

	for( i=2*s; i <= n; i*=2 )
	{
		count++;
		if( i < n && k[i] < k[i+1] )
		{
			i++;//如果右孩子大于左孩子，则指向右孩子 ，因为要指向最大的根节点 
		}

		if( temp >= k[i] )//如果根节点比子节点大，就直接撤出循环 
		{
			break;
		}
		else{
		
		k[s] = k[i];//使根节点为最大的，s的值被覆盖了 ，但是temp里有记录根节点的值 
		s = i;}//记录此时i的位置，方便等会把S被覆盖的值还给他 ，下轮循环为根节点 
	}
//为什么把这个赋值放在循环外？答案：因为值放在temp里，不会影响后续的调整 
	k[s] = temp;
}


void HeapSort(int k[], int n)
{
	int i;
//从整个树的最下方的子树开始，如9个元素，画图可知4为最左最下的子树 
	for( i=n/2; i > 0; i-- )//从最小的子树开始构建，一层一层往上,构建整个大顶堆 
	{
		HeapAdjust(k, i, n);//传进的i就是根节点，构建他的子树 
	}
//调整 
	for( i=n; i > 1; i-- )//9个元素循环8次 
	{
		swap(k, 1, i);//因为是大顶堆，数组第一个一定是最大的，将他放到数组最后一位 
		HeapAdjust(k, 1, i-1);//重新调整完，使第一个元素又为最大的 
	}
}

int main()
{
	int i, a[10] = {-1, 5, 2, 6, 0, 3, 9, 1, 7, 4};//这里是为了满足数据结构的设计，其实是9个元素，-1只是为了占领0号元素，并不参与 
//用0号元素的话不好找子树，因为根节点为i，左子树2i，右子树2i+1（层序遍历） 
	HeapSort(a, 9);

	printf("总共执行 %d 次比较!", count);
	printf("排序后的结果是：");
	for( i=1; i < 10; i++ )
	{
		printf("%d", a[i]);
	}
	printf("\n\n");

	return 0;
}
