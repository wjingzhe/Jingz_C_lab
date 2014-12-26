#include"AVLTree.h"
#include<math.h>
#include<malloc.h>
#include<stdlib.h>

bool CreateAVL(BSTree &T)//只有树根T作为参数,则构建一棵空树AVL树，返回true
{
	//则清空该树
	if(!T)
		ClearTree(T);
	return true; 
}

bool CreateAVL(BSTree &T,int n)//有树根T和元素总数作为参数,则随机生成一棵含有n个有效数据的AVL树，供演示，返回true
{
	//清空该树
	ClearTree(T);
	float *temp = (float *)malloc(sizeof(float)*n);
	int i;
	bool taller = false;
	for(i = 0;i<n;i++)
	{
		taller = false;
		temp[i]= rand()%100;
		if(!InsertAVL(T,temp[i],taller)) i--;//出现相同数据，重新生成随机数
	}
	return true; 
}


bool CreateAVL(BSTree &T,float *a,int n)   //参数有树根、数组名、数组长度，构建一棵AVL树,全部元素均为插入则返回false
{
	bool flag;
	int i = 0;
	bool taller = false;
	for(i = 0;i<n;i++)
	{
		taller = false;
		flag = InsertAVL(T,a[i],taller)||flag;
	}
	return flag;
}