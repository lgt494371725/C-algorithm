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
    
    if( (*p)->rchild == NULL )//释放67把46接到70 
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
    else//左右子树都不为空 
    {
        q = *p;
        s = (*p)->lchild;
        
        while( s->rchild )
        {
            q = s;
            s = s->rchild;//找到左子树里最右的，就是他的前驱 
        }
        
        (*p)->data = s->data;//替换节点数据 ，关系不变 
        
        if( q != *p )//因为如果左子树没有右子树，100就是直接前驱，此时数据重复 
        {
            q->rchild = s->lchild; 
        }
        else
        {
            q->lchild = s->lchild;//数据重复，此时q就是p，将s的左子树接到q的左子树 
        }
        
        free(s);
    }
    
    return TRUE;
}
