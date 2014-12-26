#include<stdio.h>
#define num 100
void main()
{
	int i,a[num];
	for(i=1;i<num;i++)
	{
		a[i] = 0;
	}
	
	a[1] = 0;
	for(i = 2;i<num;i++)
	{
		if(a[i] == 0)
		{
			int temp = i*2;
			while(temp<num)
			{
				a[temp] = 1;
				temp+=i;
			}
		}
	}

	for(i = 2;i<num;i++)
	{
		if(a[i] ==0)
		{
			printf("%d ",i);
		}
	}
}