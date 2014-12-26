#include<malloc.h>
#include<math.h>
#include"BST.h"
bool PostOrderTraverseAVL(BSTree T,bool (*Visit)(float e),float *BSTData,int &i)//正常访问返回true，当出现某个节点访问失败则返回false，并终止访问。
{
	if(T)
	{
		if(PostOrderTraverseAVL(T->rchild,Visit,BSTData,i)) 
			if(Visit(T->data))
			{	
				BSTData[i++] = T->data;
				if(PostOrderTraverseAVL(T->lchild,Visit,BSTData,i))
					return true;
			}
		return false;
	}
	else
		return true;
}

float* PostOrderAVL(BSTree T,bool (*Visit)(float e),int &n) //后序遍历，正常访问返回float数组，并打印平衡二叉树排序序列。
{
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetHeightAVL(T)));//二叉树结点至多为2^n个，n为高度
	n = 0;
	if(PostOrderTraverseAVL(T,Visit,BSTData,n))
		return BSTData;
	else
		return NULL;
}


float* PostOrderAVL(BSTree T,int &n)   //后序遍历，正常访问返回float数组，以及数组长度
{
	n = 0;
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetHeightAVL(T)));//二叉树结点至多为2^n个，n为高度
	if(PostOrderTraverseAVL(T,Nothing,BSTData,n))
		return BSTData;
	else
		return NULL;
}
