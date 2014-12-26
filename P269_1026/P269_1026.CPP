#include<stdio.h>
#include<string.h>
void main()
{
	void sort(char *name[],int n);
	void print(char *name[],int n);
	char *name[] = {"Follow me","BASIC","Great Wall","FORTRAN","Computer design"};
	//每个字符串首地址存放于name数组中
	int n = 5;
	sort(name,n);
	print(name,n);
}

void sort(char*name[],int n)
{
	char *temp;
	int i,j,k;
	for(i = 0;i<n-1;i++)
	{
		k = i;
		for(j = i+1;j<n;j++)
			if(strcmp(name[k],name[j])>0) k = j;
		if(k!=i)
		{
			temp = name[i];
			name[i] = name[k];
			name[k] = temp;
		}//if
	}//for
}
//存放地址的数组交换了所存放的地址，从而达到排序目的。

void print(char*name[],int n)
{
	int i;
	for(i = 0;i<n;i++)
		printf("%s\n",name[i]);
}