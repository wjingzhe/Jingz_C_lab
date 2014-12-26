#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void main()
{
	int a,b,c,i;
	int add;
	add=0;
	printf("Please input the start_point :");
	scanf("%d",&a);
	printf("Please input the end_point :");
	scanf("%d",&b);
/*	if(b%2==1)
	{
		b=b-1;add=1;
	};*/
	int* p=(int *)malloc(b);
	*p=1;
	*(++p)=1;
	c=b-a;
	for(i=2;i<c;p++,i++)
	{
		*(p)=*(p-1)+*(p-2);
	}
	*p=*p+add;
	printf(*p);

}