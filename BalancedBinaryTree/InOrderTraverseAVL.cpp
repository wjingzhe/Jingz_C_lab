#include<malloc.h>
#include<math.h>
#include"BST.h"
bool InOrderTraverseAVL(BSTree T,bool(*Visit)(float e),float *BSTData,int &i)//正常访问返回true，当出现某个节点访问失败则返回false，并终止访问。
{
	if(T)
	{
		if(InOrderTraverseAVL(T->lchild,Visit,BSTData,i))
			if(Visit(T->data))
			{
				BSTData[i++] = T->data;
				if(InOrderTraverseAVL(T->rchild,Visit,BSTData,i)) 
					return true;
			}

		return false;
	}
	else
		return true;
}

float* InOrderAVL(BSTree T,bool (*Visit)(float e),int &n) //中序遍历，正常访问返回一个float型数组，并打印平衡二叉树排序序列。
{
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetHeightAVL(T)));//二叉树结点至多为2^n个，n为高度
	n = 0;
	if(InOrderTraverseAVL(T,Visit,BSTData,n))
		return BSTData;
	else
		return NULL;
}

float* InOrderAVL(BSTree T,int &n) //中序遍历，正常访问返回一个float型数组，数组长度。
{
	n = 0;
	float *BSTData = (float*)malloc(sizeof(float)*(int)pow(2,GetHeightAVL(T)));//二叉树结点至多为2^n个，n为高度
	if(InOrderTraverseAVL(T,Nothing,BSTData,i))
		return BSTData;
	else
		return NULL;
}