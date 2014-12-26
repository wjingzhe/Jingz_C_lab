#include<stdio.h>
#include <stdlib.h>
#define n 15
void main()
{
	char sign='y';
	int i,j,min,temp,num,a[n],m=n;
	printf("Please input 15 nums:\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
				min=j;
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
			min=i;
		}
	
	}
	for(i=0;i<n;i++)
		{
			printf("%4d",a[i]);
		}
	printf("\n");

while(sign=='y'||'Y')
	{
		printf("Please intput number to look for:");
	    scanf("%d",&num);
		for(i=0;i<n/4;i++)
		{
			if(num==a[(m-1)/2])
			{
				i=(m-1)/2;
				printf("a[%d]=%d\n",i,a[i]);
				goto loop;
			}
		    else if(num>a[(m-1)/2])
				{
					m=(m-1)/2+m-1;
				}
			else {m=(m-1)/2;}
		}
	    printf("It's not exsiting in the list\n");
loop:printf("continue or not?(Y/N)\n");
		scanf("%c",&sign);
		while((sign!='Y')&&(sign!='N')&&(sign='y')&&(sign!='n'))
				{
					printf("Eror.Please choose 'Y' or 'N'.");
					scanf("%c",&sign);
				}
	 }
}
