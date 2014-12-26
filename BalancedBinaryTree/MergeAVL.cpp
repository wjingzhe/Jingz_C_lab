#include<malloc.h>
#include<stdio.h>
#include"BST.h"
BSTree MergeAVL(BSTree &p,BSTree &q) // 合并两棵平衡二叉树
{
	int i = 0,j = 0;
	bool taller = false;
	float *BSTData = PreOrderAVL(q,i);
	for(j = 0;j<=15;j++)
	{
		if(!InsertAVL(p,BSTData[j],taller))
			printf("存在相同的元素");
	}
	DestroyTree(q);
	return p;	
}