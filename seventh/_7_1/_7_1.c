#include<stdio.h>
#include<math.h>
void main()
{
	int i,j,n;
	int a[100];
	for(i=0;i<100;i++)
		a[i]=i+1;
	a[0]=0;
	for(i=1;i<sqrt(100);i++)
	{
		for(j=i+1;j<100;j++)
		{
			if(a[i]!=0&&a[j]!=0&&a[j]%a[i]==0)
				a[j]=0;
		}
	}
	for(i=0;i<100;i++)
	{
		if(a[i]!=0)
		{
			printf("%5d",a[i]);
			n++;
		}
		if(n%10==0)
		{
			printf("\n");
			n=0;
		}
	}
}