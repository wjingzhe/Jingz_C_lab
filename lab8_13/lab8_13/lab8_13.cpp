// lab8_13.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include<stdio.h>
void main()
{
	void sort(int array[],int n);
	int a[10],i;
	printf("enter the array\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	sort(a,10);
	printf("the sorted array:\n");
	for(i=0;i<10;i++)
		printf("%5d",a[i]);
	printf("\n");
}

void sort(int arr[],int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(arr[j]<arr[k])
				k=j;
		t=arr[k];arr[k]=arr[i];arr[i]=t;
	}
}