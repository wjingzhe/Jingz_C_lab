#include"BST.h"
int GetHeightAVL(BSTree T)
{
	int l,r;
	if(T==NULL) return 0;
	else 
	{
		l = GetHeightAVL(T->lchild)+1;
		r = GetHeightAVL(T->rchild)+1;

		return l>r?l+1:r+1;
	}

}