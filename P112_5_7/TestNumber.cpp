#include<stdio.h>
void main()
{
	long num;
	scanf("%ld",&num);
	int a[5];
	for(int i = 0;num>0&&i<5;num = num/10,i++)
	{
		a[i] = num%10;
		printf("%ld\n",a[i]);
	}
	printf("%d\n",i);
	for(int j=0;j<i;j++)
	{
		printf("%ld",a[j]);
	}
	printf("\n");
}