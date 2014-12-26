#include<stdio.h>
void main()
{
	int i,j,num;
	int a[11]={1,4,6,9,13,16,19,28,40,100};
	printf("array a:\n");
	for(i=0;i<11;i++)
		printf("%5d",a[i]);
	printf("\n");
	printf("Please enter a number named 'num':");
	scanf("%d",&num);
	if(a[9]<num)
		a[10]=num;
	else
	{
		for(i=0;i<10;i++)
		{
			if(a[i]>num)
			{
				for(j=9;j>=i;j--)
					a[j+1]=a[j];
				a[i]=num;
				break;
				
			}
			
		}
	}
	printf("\n");
	printf("array a:\n");
	for(i=0;i<11;i++)
		printf("%5d",a[i]);
	printf("\n");

}