#include<stdio.h>
#define n 10
void main()
{
	int a[n][n]={0};
	int i,j;
	for(i=0;i<n;i++)
	{
		a[i][0]=1;
		a[i][i]=1;
	}
	for(i=2;i<n;i++)
	{
		for(j=1;j<=i-1;j++)
		{		
			a[i][j]=a[i-1][j-1]+a[i-1][j];		
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}