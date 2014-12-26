#include"BST.h"
#include<stdio.h>

bool PrintfBST(float e)//访问该节点，并存放于数组a中，返回true，内存申请失败则返回false
{
	printf("%6.1f ",e);
	return true;
}
bool Nothing(float e)
{
	return true;
}