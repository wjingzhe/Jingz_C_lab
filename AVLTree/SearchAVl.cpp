#include"AVLTree.h"
bool SearchAVL(BSTree T,float key,BSTree f,BSTree &p)
{
	//根据指针T所指向二叉排序树中递归地查找其关键字等于key的数据
	//若查找成功，则指针p指向该数据元素结点并返回true，
	//否则指针p指向查找路径上访问的最后一个结点并返回false，指针f指向T的双亲，其初始值为NULL
	if(!T)
	{p = f;return false;}
	else if(key==T->data) {p = T;return true;}
	else if(key<T->data) return SearchAVL(T->lchild,key,T,p);
	else return SearchAVL(T->rchild,key,T,p);
}//SearchAVL