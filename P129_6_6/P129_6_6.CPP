#include<stdio.h>
#include<math.h>
void main()
{       
	for(int i =100,a,b,c;i<1000;i++)
	{
		
		a = i%10;
		b = i/10 %10;
		c = i/100;
		if(i == (a*a*a+b*b*b+c*c*c))
		{
			printf("%d ",i);
		}
	}
}
