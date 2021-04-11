Status DeleteBST(BiTree *T, int key)
{
    if( !*T )
    {
        return FALSE;
    }
    else
    {
        if( key == (*T)->data )
        {
            return Delete(T);
        }
        else if( key < (*T)->data )
        {
            return DeleteBST(T->lchild, key);
        }
        else
        {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
}

Status Delete(BiTree *p)
{
    BiTree q, s;
    
    if( (*p)->rchild == NULL )//�ͷ�67��46�ӵ�70 
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else if( (*p)->lchild == NULL )
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else//������������Ϊ�� 
    {
        q = *p;
        s = (*p)->lchild;
        
        while( s->rchild )
        {
            q = s;
            s = s->rchild;//�ҵ������������ҵģ���������ǰ�� 
        }
        
        (*p)->data = s->data;//�滻�ڵ����� ����ϵ���� 
        
        if( q != *p )//��Ϊ���������û����������100����ֱ��ǰ������ʱ�����ظ� 
        {
            q->rchild = s->lchild; 
        }
        else
        {
            q->lchild = s->lchild;//�����ظ�����ʱq����p����s���������ӵ�q�������� 
        }
        
        free(s);
    }
    
    return TRUE;
}
