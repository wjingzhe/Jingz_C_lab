#include"AVLTree.h"
int GetDepthAVL(BSTree T)
{
	int l,r;
	if(T==NULL) return 0;
	else 
	{
		l = GetDepthAVL(T->lchild)+1;
		r = GetDepthAVL(T->rchild)+1;

		return l>r?l+1:r+1;
	}

}