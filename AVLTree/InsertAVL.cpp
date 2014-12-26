#include<malloc.h>
#include"AVLTree.h"
void LeftBalance(BSTree &T);
void RightBalance(BSTree &T);

void R_Rotate(BSTree &p)
{
	//在左孩子的左子树插入：左左插入，需要右旋
	//对以*p为根的二叉排序树做右旋处理，处理之后p指向新的跟结点
	//即旋转前的左子树的根结点

	BSTree lc = p->lchild;  //lc指向*p的左子树的根结点
	p->lchild = lc->rchild; //lc右子树挂接为*p的左子树，让p可挂接为lc的右子树
	lc->rchild = p;
	p = lc;//指向新的根节点
}//R_Rotate

void L_Rotate(BSTree &p)
{
	//在右孩子的右子树插入：右右插入，需要左旋
	//对以*p为根的二叉排序树做右旋处理，处理之后p指向新的跟结点
	//即旋转前的右子树的根结点

	BSTree rc = p->rchild;  //rc指向*p的右子树的根结点
	p->rchild = rc->lchild; //rc左子树挂接为*p的右子树，让p可挂接为rc的左子树
	rc->lchild = p;
	p = rc;//指向新的根节点
}//L_Rotate

void LeftBalance(BSTree &T)
{
	//对以指针T所指向结点为根的二叉树做左平衡处理，
	//本函数结束后指针T指向新的根节点
	BSTree lc = T->lchild;  //lc指向T的左子树根节点
	switch(lc->bf) //检查lc的平衡度，并作相应的平衡处理
	{
	case LH: //新结点插入在T的左孩子的左子树上，要做单右旋处理，处理后平衡度为EH
		T->bf = lc->bf = EH;
		R_Rotate(T);
		break;

	case RH: //新节点插入在T的左孩子的右子树上，要做双旋处理（先左后右）
		BSTree rd = lc->rchild;       //rd指向T的左孩子的右子树根结点
		switch(rd->bf)          //根据情况修改T以及其左子树的平衡因子，
		{          //因为rd的左孩子挂接为lc的右孩子，rd的右孩子挂接为T的左孩子
		case LH:
			T->bf = RH;
			lc->bf = EH;
			break;

		case EH:
			T->bf = lc->bf = EH;
			break;

		case RH:
			T->bf = EH;
			lc->bf = LH;
			break;
		}//switch(rd->bf)

		rd->bf = EH;
		L_Rotate(T->lchild); //对T的左子树做左旋平衡处理
		R_Rotate(T); //对T做右旋平衡处理
	}//switch(lc->bf)
}//LeftBalance

void RightBalance(BSTree &T)
{
	//对以指针T所指向结点为根的二叉树做右平衡处理，
	//本函数结束后指针T指向新的根节点
	BSTree rc = T->rchild;  //lc指向T的左子树根节点
	switch(rc->bf) //检查rc的平衡度，并作相应的平衡处理
	{
	case RH: //新结点插入在T的右孩子的右子树上，要做单旋左处理，处理后平衡度为EH
		T->bf = rc->bf = EH;
		L_Rotate(T);
		break;

	case LH:      //新节点插入在T的右孩子的左子树上，要做双旋处理（先右后左）
		BSTree ld = rc->lchild;    //ld指向T的右孩子的左子树根结点
		switch(ld->bf)               //根据情况修改T以及其右子树的平衡因子，
		{//因为ld的左孩子挂接为lc的右孩子，rd的右孩子挂接为T的左孩子
		case LH:
			T->bf = EH;
			rc->bf = RH;
			break;

		case EH:
			T->bf = rc->bf = EH;
			break;

		case RH:
			T->bf = LH;
			rc->bf = EH;
			break;
		}//switch(ld->bf)

		ld->bf = EH;
		R_Rotate(T->rchild); //对T的右子树做右旋平衡处理
		L_Rotate(T); //对T做左旋平衡处理
	}//switch(lc->bf)
}//Leftbalance322


bool InsertAVL(BSTree &T,float e,bool &taller)
{
	//若在平衡的二叉排序树T中部存在和e有相同关键字的结点，则插入一个数据元素
	//为e的新节点，并返回1，否则返回0.若因插入而使二叉排序树失去平衡，则作平衡旋转处理
	//布尔变量taller反映T长高与否
	if(!T)
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = e;
		T->lchild = T->rchild = NULL;
		T->bf = EH;
		taller = true;
		return true;
	}//if
	else
	{
		if(e==T->data)//已存在e，不再插入
		{
			taller = false;
			return false;
		}//if
		else if(e<T->data)//小于T->data，在T的左子树中继续插入
		{
			if(!InsertAVL(T->lchild,e,taller)) return false; // 未插入
			if(taller) //已插入到*T的左子树中且左子树“长高”
				switch(T->bf)//检查T的平衡度
				{
					case LH://原本左子树比右子树高，需要做左平衡处理
						LeftBalance(T);
						taller = false;
						break;
					case EH://原本等高，现因左子树增高而使树增高
						T->bf = LH;
						taller = true;
						break;
					case RH:// 原本右子树比左子树高，现在等高
						T->bf = EH;
						taller = false;
						break;
				}//switch(T->bf)
			return true;
		}//if_else
		else //在T的右子树中继续插入
		{
			if(!InsertAVL(T->rchild,e,taller)) return false;// 未插入
			if(taller) //已插入到*T的右子树中且右子树“长高”
				switch(T->bf) //检查T的平衡度
				{
					case LH: //原本左子树比右子树高，现在等高
						T->bf = EH;
						taller = false;
						break;
					case EH: //原本等高，现因右子树增高而使右子树增高
						T->bf = RH;
						taller = true;
						break;
					case RH: //原本右子树比左子树高，需要作右平衡处理
						RightBalance(T);
						taller = false;
						break;
				}//switch(T->bf)
			return true;
		}//if_else if_else
		
	}//if_else

}//InsertACL

