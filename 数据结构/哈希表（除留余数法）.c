https://blog.csdn.net/yyyljw/article/details/80903391
#define HASHSIZE 12
#define NULLKEY -32768

typedef struct
{
	int *elem;	// ����Ԫ�صĻ�ַ����̬��������
	int count;	// ��ǰ����Ԫ�صĸ���
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

// ʹ�ó���������
int Hash(int key)
{
	return key % HASHSIZE;
}

// ����ؼ��ֵ�ɢ�б�
void InsertHash(HashTable *H, int key)
{
	int addr;
	
	addr = Hash(key);//���Խ����Ż�����Ϊ��������Ǹ�С��ַ 
	
	while( H->elem[addr] != NULLKEY )	// �����Ϊ�գ����ͻ����
	{
		addr = (addr + 1) % HASHSIZE;	// ʹ�ÿ��Ŷ�ַ�����ɢ�г�ͻ �����������Ϊ�˷�ֹ�µĵ�ַ�������鳤�� 
	}
	
	H->elem[addr] = key;
}

// ɢ�б���ҹؼ���
int SearchHash(HashTable H, int key, int *addr)
{
	*addr = Hash(key);//ע��ֱ����ָ������˷��ص�������ֵ 
	
	while( H.elem[*addr] != key )//����ĵ�ַ��ŵĲ���key 
	{
		*addr = (*addr + 1) % HASHSIZE;//���Ŷ�ַ�� 
		if( H.elem[*addr] == NULLKEY || *addr == Hash(key) ) //�ص�ԭ���ˣ����߲鵽δ������� 
		{
			return -1;
		}
	}
	
	return 0;
}
int main()
