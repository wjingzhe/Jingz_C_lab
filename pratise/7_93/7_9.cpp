#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 4
void main()
{
	char sign;
	int t;//判断是查找到，t==0的时候找不到；
	int i,j,min,temp,a[n],m=n;
	int search(int* b);
	printf("Please input the nums:\n");
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
	sign='Y';
	while(sign=='Y')
	{
		 t=search(a);
         if(t==0)
         {
            printf("找不到该数字\n");
         }
         else
		 {
            printf("找到了该数字，该数字在数组中的下标是 %d\n",t);
         }
         printf("continue or not?(Y/N)\n");
		 scanf("%c",&sign);
	}
}

int search(int* a)
{
        int start=0,end=n-1,num,mid;//start是初始位置，end 是最后的位置
        printf("Please intput number to look for:");
	    scanf("%d",&num);
		while(start<=end)
		{
		    mid=(start+end)/2;
			if(num==a[mid])
			{
				return mid;//找到的话。返回找到的位置
			}
		    else if(num>a[mid])
				{
					start=mid+1;
				}
			else
			{
			    end=mid-1;
			}
		}
		return 0;
}
