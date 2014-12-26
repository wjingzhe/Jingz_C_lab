#include"AVLTree.h"
#include<iostream>
using namespace std;
int DispAVL(BSTree T,int i)//以凹凸表（上右子树，下左子树的形式）打印显示
{
	if(T) //空子树不打印空行
	{
		DispAVL(T->rchild,i+1); //中序遍历，先打印右子树
		int j = 0;
		
		for(;j<2*i-1-1;j++) //前2*i-2项为空
			printf("   ");
		printf("%6.1f",T->data); //第2*i-1项为二叉树结点
		cout<<endl;
		DispAVL(T->lchild,i+1); //打印左子树
	}
	return 1;
}