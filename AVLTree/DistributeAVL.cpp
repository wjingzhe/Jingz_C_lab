#include<malloc.h>
#include"AVLTree.h"

bool DistributeAVL(BSTree &p,BSTree &q) //分裂后的的森林有两棵树，都是平衡二叉树，原树根元素插入原树的右子树，原根指向其右子树，原树的左子树作为拆分新树；
{
	
	BSTree s = p;
	q = p->lchild;
	bool taller = false;
	InsertAVL(p->rchild,p->data,taller);
	p = p->rchild;
	free(s);
	s = NULL;
	return true;
}