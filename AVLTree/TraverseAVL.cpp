#include"AVLTree.h"
#include<stdio.h>
int TraverseAVL(BSTree T)
{
	//空树返回0；错误返回-1，正常显示返回1
	if(!T)  	
	{
		printf("T is an empty tree.");
		return 0;//空树
	}
	else 
	{
		return DispAVL(T,1);//树形显示
	}
}