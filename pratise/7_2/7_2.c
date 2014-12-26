#include<stdio.h>
void main()
{
	int i,j,a[10],max;
	printf("Please enter Integer data:\n");
	for(i=0;i<10;i++)
	{
		printf("a[%i]=",i);
		scanf("%d",&a[i]);
	}
	printf("\nThe original numbers:\n");
	for(i=0;i<10;i++)
		printf("%5d",a[i]);
	for(i=0;i<10;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(a[i]>a[j])
			{
				max=a[i];
				a[i]=a[j];
				a[j]=max;
			}

		}
	}
	printf("\nThe sorted numbers:\n");
	for(i=0;i<10;i++)
		printf("%5d",a[i]);
	printf("\n");
}