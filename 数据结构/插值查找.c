
#include <stdio.h>
 
int bin_search( int str[], int n, int key )
{
    int low, high, mid;
    
    low = 0;
    high = n-1;

    while( low <= high )//ע�����ѭ���������п�������û����������п��ܱ����ж�����߶�С 
    {
        mid = low + (key-str[low])/(str[high]-str[low])*(high-low); // ��ֵ���ҵ�Ψһ��ͬ�� 
        
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
//��ֵ����ǰ�������ݰ�˳�������ҷֲ��ȽϾ��� 
int main()
{
    int str[11] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int n, addr;

    printf("����������ҵĹؼ���: ");
    scanf("%d", &n);

    addr = bin_search(str, 11, n);
    if( -1 != addr )
    {
        printf("%d����λ��%d\n", n, addr);
    }
    else
    {
        printf("����ʧ��\n");
    }

    return 0;
}
