#include<malloc.h>
#include<math.h>
#include"AVLTree.h"
bool PostOrderAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i)//正常访问返回true，当出现某个节点访问失败则返回false，并终止访问。
{
	if(T)
	{
		if(PostOrderAVL(T->rchild,Visit,BSTData,i)) 
		{	
			if(PostOrderAVL(T->lchild,Visit,BSTData,i))
			{
				if(Visit(T->data))
				{
					BSTData[i++] = T->data;
					return true;
				}
				else 
					return false;
			}
			else
				return false;
		}//if_先
		return false;
	}//if_T
	else
		return true;
}

float* PostOrderTraverseAVL(BSTree T,bool (*Visit)(float e),int &n) //后序遍历，正常访问返回float数组，并打印平衡二叉树排序序列。
{
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetDepthAVL(T)));//二叉树结点至多为2^n个，n为高度
	n = 0;
	if(PostOrderAVL(T,Visit,BSTData,n))
		return BSTData;
	else
		return NULL;
}


float* PostOrderTraverseAVL(BSTree T,int &n)   //后序遍历，正常访问返回float数组，以及数组长度
{
	n = 0;
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetDepthAVL(T)));//二叉树结点至多为2^n个，n为高度
	if(PostOrderAVL(T,Nothing,BSTData,n))
		return BSTData;
	else
		return NULL;
}
