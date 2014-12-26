#include"BST.h"
#include<stdio.h>
int TraverseAVL(BSTree T,int i)
{
	//空树返回0；错误返回-1，正常显示返回1
	if(!T)  	
	{
		printf("T is an empty tree.");
		return 0;//空树
	}
	else 
	{
		return DispAVL(T,i);//树形显示
	}
}