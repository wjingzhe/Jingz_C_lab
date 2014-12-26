#include<stdio.h>
void main()
{
	int a[16][16],i,j,k,n,p;
	p=1;
	while(p==1)
	{
		printf("enter n(n=1 to 15):");
		scanf("%d",&n);
		if((n>0)&&(n<16) && (n%2!=0))
			p=0;
	}
	/*初始化*/
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
		/*建立魔方阵*/
	j=n/2;
	a[0][j]=1;
	for(k=1;k<n*n;k++)
	{
		i=i-1;
		j=j+1;
		if((i<0) && (j>n-1))
		{
			i=i+2;
			j=j-1;
		}
		else
		{
			if(i<0)
				i=n-1;
			if(j>n-1)
				j=0;
		}
		if(a[i][j]==0)
			a[i][j]=k;
		else
		{
			i=i+2;
			j=j-1;
			a[i][j]=k;
		}
	}
	/*输出魔方阵*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
}