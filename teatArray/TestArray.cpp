#include<stdio.h>
void main()
{
	int f[20] = {1,1};
	for(int i=2;i<20;i++)
	{
		f[i] = f[i-1]+f[i-2];
	}
	for(i = 0;i<20;)
	{
	
		printf("%12d",f[i]);
		i++;
		if(i%5==0) printf("\n");
	}
}