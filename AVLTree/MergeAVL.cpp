#include<malloc.h>
#include"AVLTree.h"
#include<iostream>
using namespace std;

BSTree MergeAVL(BSTree &p,BSTree &q) // 合并两棵平衡二叉树
{
	int i = 0,j = 0;
	bool taller = false;
	float *BSTData = InOrderTraverseAVL(q,i);
	for(j = 0;j<i;j++)
	{
		if(!InsertAVL(p,BSTData[j],taller))
			cout<<"存在相同的元素"<<endl;
	}
	ClearTree(q);
	return p;	
}