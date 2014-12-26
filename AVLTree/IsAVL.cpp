#include"AVLTree.h"
bool IsAVL(BSTree T)//判定是否为一棵平衡二叉树,是则返回true，否则返回false
{
	if(T==NULL) return true;
	else if(T->lchild&&T->rchild)
		return (-2<T->bf)&&(T->bf<2)&&(T->lchild->data<T->data)&&(T->rchild->data>T->data)&&(IsAVL(T->lchild))&&(IsAVL(T->rchild));
	else if(T->rchild)
		return (-2<T->bf)&&(T->bf<2)&&(T->rchild->data>T->data)&&(IsAVL(T->rchild));
	else if(T->lchild)
		return (-2<T->bf)&&(T->bf<2)&&(T->lchild->data<T->data)&&(IsAVL(T->lchild));
	else
		return true;
}