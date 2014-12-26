#include<malloc.h>
#include"BST.h"

BSTree DistributeAVL(BSTree p) //分裂后的的森林有两棵树，都是平衡二叉树，原树根指向原树的右子树，原树的左子树作为返回值
{
	BSTree q = p->lchild,s = p;
	bool taller = false;
	InsertAVL(q,p->data,taller);
	p = p->rchild;
	free(s);
	return q;
}
