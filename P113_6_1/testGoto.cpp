#include<stdio.h>
void main()
{
	int i,sum = 0;
	i = 1;
lp:if(i<=100)
	 {
		 sum = sum +i;
		 i++;
		 goto lp;
	 }
	 printf("%d\n",sum);
}