#include<stdio.h>
#include<malloc.h>
#define LH 1;
#define EH 0;
#define RH -1;

typedef struct BSTNode
{
	int data;
	int bf;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

void R_Rotate(BSTree &p)
{
	//对以*p为根的二叉排序树做右旋处理，
	//处理之后p指向新的树根结点，
	//即旋转处理之前的左子树的根节点
	BSTNode *lc = p->lchild;    //lc指向*p的左子树根结点
	p->lchild = lc->rchild;    //lc的右子树挂接为*p的左子树
	lc->rchild = p;
	p = lc;    //p指向新的跟结点
}//R_Rotate

void L_Rotate(BSTree &p)
{
	//对以*p为根的二叉排序树做左旋处理，
	//处理之后p指向新的树根结点，
	//即旋转处理之前的右子树的根节点
	BSTNode *rc = p->rchild;
	p->rchild = rc->lchild;
	rc->lchild = p;
	p = rc;
}//L_Rotate

void LeftBalance(BSTree &T)
{

	BSTNode *lc = T->lchild;
	switch(lc->bf)
	{
	case LH:
		T->bf = lc->bf = EH;;
		R_Rotate(T);
		break;
	case RH:
		BSTNode *rd = lc->rchild;
		switch(rd->bf)
		{
		case LH:T->bf = RH; lc->bf = EH;break;
		case EH:T->bf = lc->bf = EH;break;
		case LH:T->bf = EH; lc->bf = LH;break;
		}//swtich(rd->bf)
		rd->bf = EH;
		L_Rotate(T->lchild);
		R_Rotate(T);
	}//switch(lc->bf)

}//LeftBalance

void RightBalance(BSTree &T)
{

	BSTNode *lc = T->lchild;
	switch(lc->bf)
	{
	case LH:
		T->bf = lc->bf = EH;;
		R_Rotate(T);
		break;
	case RH:
		BSTNode *rd = lc->rchild;
		switch(rd->bf)
		{
		case LH:T->bf = RH; lc->bf = EH;break;
		case EH:T->bf = lc->bf = EH;break;
		case LH:T->bf = EH; lc->bf = LH;break;
		}//swtich(rd->bf)
		rd->bf = EH;
		L_Rotate(T->lchild);
		R_Rotate(T);
	}//switch(lc->bf)

}//RightBalance


int InsertAVL(BSTree &T,int e,bool &taller)
{
	if(!T)
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = e;
		T->lchild = T->rchild = NULL;
		T->bf = EH;
		taller = true;
		return 1;
	}
	else {
		if(e == T->data)
		{//已存在和e相同关键字的结点
			taller = false;return 0;
		}
		if(e<T->data)
		{
			if(!InsertAVL(T->lchild,e,taller)) 
				return 0;
			if(taller)
			{
				switch(T->bf)
				{
				case LH:
					LeftBalance(T);
					taller = false;
					break;
				case EH:
					T->bf = LH;
					taller = true;
					break;
				case RH:
					T->bf = EH;
					talller = false;
					break;
				}//switch(T->bf)
			}
		}//if
		else {
			if(!InsertAVL(T->rchild,e,taller))
				return 0;
			if(taller)
			{
				switch(T->bf)
				{
				case LH:
					T->bf = EH;
					taller = false;
					break;
				case EH:
					T->bf = RH;
					talller = true; 
					break;
				case RH:
					RightBalance(T);
					talller = false;
					break;
				}//switch(T->bf)
			}
		}//else
		
	}//else

	return 1;
}//InsertAVL

