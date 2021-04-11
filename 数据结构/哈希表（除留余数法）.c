https://blog.csdn.net/yyyljw/article/details/80903391
#define HASHSIZE 12
#define NULLKEY -32768

typedef struct
{
	int *elem;	// 数据元素的基址，动态分配数组
	int count;	// 当前数据元素的个数
}HashTable;

int InitHashTable(HashTable *H)
{
	H->count = HASHSIZE;
	H->elem = (int *)malloc(HASHSIZE * sizeof(int));
	if( !H->elem )
	{
		return -1;
	}
	for( i=0; i < HASHSIZE; i++ )
	{
		H->elem[i] = NULLKEY;
	}
	return 0;
}

// 使用除留余数法
int Hash(int key)
{
	return key % HASHSIZE;
}

// 插入关键字到散列表
void InsertHash(HashTable *H, int key)
{
	int addr;
	
	addr = Hash(key);//可以进行优化，因为现在这个是个小地址 
	
	while( H->elem[addr] != NULLKEY )	// 如果不为空，则冲突出现
	{
		addr = (addr + 1) % HASHSIZE;	// 使用开放定址法解决散列冲突 ，这里除余是为了防止新的地址超过数组长度 
	}
	
	H->elem[addr] = key;
}

// 散列表查找关键字
int SearchHash(HashTable H, int key, int *addr)
{
	*addr = Hash(key);//注意直接用指针接受了返回的整形数值 
	
	while( H.elem[*addr] != key )//如果改地址存放的不是key 
	{
		*addr = (*addr + 1) % HASHSIZE;//开放定址法 
		if( H.elem[*addr] == NULLKEY || *addr == Hash(key) ) //回到原点了，或者查到未存放区域 
		{
			return -1;
		}
	}
	
	return 0;
}
int main()
