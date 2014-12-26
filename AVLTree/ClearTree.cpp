#include"AVLTree.h"
#include<malloc.h>
void ClearTree(BSTree &T)//假如T不为空，则销毁T
{	                        
	if(T) 
	{
		ClearTree(T->lchild);                          //销毁T的左子树
	    ClearTree(T->rchild);                          //销毁T的右子树
		free(T); 
		T=NULL; 
	}
}