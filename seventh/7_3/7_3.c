#include<stdio.h>
void main()
{
	int a[10];
	int i,j,k,t;
	printf("Please input 10numbes: \n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	printf("\n");
	for(j=0;j<9;j++)
	{
		for(k=0;k<9-j;k++)
			if(a[k]>a[k+1])
			{
				t=a[k];
				a[k]=a[k+1];
				a[k+1]=t;
			}
	}
	printf("The sorted numbers :\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
}