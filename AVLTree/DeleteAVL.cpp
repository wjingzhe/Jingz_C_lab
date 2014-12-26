#include<malloc.h>
#include"AVLTree.h"
int DeleteAVL(BSTree &T,float key,bool &lower)
{
	//0表示不存在该元素，1表示正常删除
	if(!T) return 0;
	else if(key==T->data)
	{
		BSTree p,q = T;
		float temp; //存放T的左子树中的最大值，作为T的新数据
		if(!T->rchild)                                 //要删除没有右子树的结点，重接左子树，并删除结点（含叶子结点）
		{
			T = T->lchild;
			free(q);
			lower = true;
		}
		else if(!T->lchild)                            //要删除没有左子树的结点，重接右子树，并删除结点（含叶子结点）
		{
			T = T->rchild;
			free(q);
			lower = true;
		}
		else                                //左右子树都有，找*p左子树的最大值作为新的根结点，将p变为叶子结点删除　　　　　　　　　　　　　　　　　　　　
		{
			p = T->lchild;
			while(p->rchild)
			{
				p = p->rchild;
			}
			temp = p->data;
			DeleteAVL(T,temp,lower);      //temp的值一定存在，且为叶子结点
			q->data = temp;
		}
	}//else_if
	else if(key<T->data) //在左子树中继续删除
	{
		if(!DeleteAVL(T->lchild,key,lower)) return 0;
		if(lower&&--T->bf<=-2)
		{
			RightBalance(T);
			lower = false;
		}//if_lower 相当于T的右子树新插入一个结点引发的不平衡状态

	}//else_if
	else //在右子树中继续删除
	{
		if(!DeleteAVL(T->rchild,key,lower)) return 0;
		if(lower&&++T->bf>=2)
		{
			LeftBalance(T);
			lower = false;
		}//if_lower 相当于T的左子树新插入一个结点引发的不平衡状态

	}//else

	return 1;//正常删除
}