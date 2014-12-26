#include<stdio.h>
void main()
{
	int a[3][3],sum=0,i,j;
	printf("Please enter integer\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			printf("a[%i][%j]=",i,j);
			scanf("%d",&a[i][j]);
		}
	for(i=0;i<3;i++)
		sum+=a[i][i];
	printf("sum=%6d\n",sum);
}