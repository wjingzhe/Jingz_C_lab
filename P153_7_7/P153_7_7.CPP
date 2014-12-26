#include<stdio.h>
#define N 16
void main()
{
	int a[N][N] = {0};
	int i,j,k,p,m,n;
	p = 1;
	while(p==1)
	{
		printf("Enter n(1~%d):",N-1);
		scanf("%d",&n);
		if((n!=0)&&(n<N)&&(n%2!=0)) 
			p = 0;
	}
	i = 1;
	j = n/2+1;
	a[1][j] = 1;
	for(k=2;k<=n*n;k++)
	{
		i = i-1;
		j = j+1;
		if((i<1) && (j>n))
		{
			i = i+2;
			j = j-1;
		}
		else 
		{
			if(i<1) i = n;
			if(j>n) j = 1;
		}

		if(a[i][j]==0) a[i][j] = k;
		else
		{
			i+=2;
			j-=1;
			a[i][j] = k;
		}

	}//for

	for(i = 1;i<=n;i++)
	{
		for(j = 1;j<=n;j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
}