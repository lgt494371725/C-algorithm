
#include <stdio.h>
 
int bin_search( int str[], int n, int key )
{
    int low, high, mid;
    
    low = 0;
    high = n-1;

    while( low <= high )//注意这个循环条件，有可能数组没有这个数，有可能比所有都大或者都小 
    {
        mid = low + (key-str[low])/(str[high]-str[low])*(high-low); // 插值查找的唯一不同点 
        
        if( str[mid] == key )
        {
            return mid;              
        }
        if( str[mid] < key )
        {
            low = mid + 1;       
        }
        if( str[mid] > key )
        {
            high = mid - 1;       
        }
    }

    return -1;                      
}
//插值查找前提是数据按顺序排列且分布比较均匀 
int main()
{
    int str[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int n, addr;

    printf("请输入带查找的关键字: ");
    scanf("%d", &n);

    addr = bin_search(str, 11, n);
    if( -1 != addr )
    {
        printf("%d所在位置%d\n", n, addr);
    }
    else
    {
        printf("查找失败\n");
    }

    return 0;
}
