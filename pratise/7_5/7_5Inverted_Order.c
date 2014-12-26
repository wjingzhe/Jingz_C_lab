#include<stdio.h>
#define N 5
void main()
{
	int a[N];
	int i,temp;
	printf("enter array a (%d nums):\n",N);
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
    printf("The original order is:");
	for(i=0;i<N;i++)
		printf("%5d",a[i]);
	for(i=0;i<N/2;i++)
	{
		temp=a[i];
		a[i]=a[N-1-i];
		a[N-1-i]=temp;
	}
	printf("\nThe inverted order is:");
	for(i=0;i<N;i++)
		printf("%5d",a[i]);
	printf("\n");
}