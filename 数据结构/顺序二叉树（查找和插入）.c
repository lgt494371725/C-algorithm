// �������Ķ���������ṹ����
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// �ݹ���Ҷ��������� T ���Ƿ���� key
// ָ�� f ָ�� T ��˫�ף����ʼֵ����ֵΪ NULL
// �����ҳɹ�����ָ�� p ָ�������Ԫ�ؽ�㣬������ TRUE
// ����ָ�� p ָ�����·���Ϸ��ʵ����һ����㣬������ FALSE
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)//������ֻ��p��Ҫ�ı��ַ������p��˫ָ�� 
{
    if( !T )    // ���Ҳ��ɹ�
    {
        *p = f;
        return FALSE;
    }
    else if( key == T->data )   // ���ҳɹ�
    {
        *p = T;
        return TRUE;
    }
    else if( key < T->data )
    {
        return SearchBST( T->lchild, key, T, p );   // ����������������
    }
    else
    {
        return SearchBST( T->rchild, key, T, p );   // ����������������
    }


// ������������ T �в����ڹؼ��ֵ��� key ������Ԫ��ʱ��
// ���� key ������ TRUE�����򷵻� FALSE
Status InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if( !SearchBST(*T, key, NULL, &p) )
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        
        if( !p ) //p���ϴβ���������һ���ڵ�    
        {
            *T = s;     // ���� s Ϊ�µĸ����
        }
        else if( key < p->data )
        {
            p->lchild = s;  // ���� s Ϊ����
        }
        else
        {
            p->rchild = s;  // ���� s Ϊ�Һ���
        }
        return TRUE;
    }
    else
    {
        return FALSE;   // �������йؼ�����ͬ�Ľ�㣬���ٲ���
    }
}




