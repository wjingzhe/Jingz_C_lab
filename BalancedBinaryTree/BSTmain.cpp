#include<stdio.h>
#include"BST.h"
void main()
{
	float a[10] = {13,24,37,90,53,14,10,8,6,15};
	bool taller = false,lower = false;
	BSTree T=NULL; 
	for(int i = 0;i<10;i++)
	{
		InsertAVL(T,a[i],taller);
		
	}
	
	BSTree f = NULL;
	BSTree p;
	SearchAVL(T,14.5,f,p);
	if(!TraverseAVL(T,1)) return;
	printf("\n-------------------------------------\n");
	printf("\n %4.1f address is %ld\n",14.5,p);
	printf("\n-------------------------------------\n");
	if(!DeleteAVL(T,14,lower)) {printf("%f该元素不存在.");}
	if(!TraverseAVL(T,1)) return;
	
	return;
}