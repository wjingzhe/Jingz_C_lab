#include<stdio.h>
#include<math.h>
void main()
{
	float a,b,c,disc,x1,x2,realpart,imagpart;
	scanf("%f,%f,%f",&a,&b,&c);
	printf("The equation ");
	
	if(fabs(a)<1e-6)
	{
		printf("is not a quadratic\n");
	}

	else 
	{
		disc = b*b - 4*a*c;
		if(fabs(disc)<=1e-6)
		{
			printf("has two equal roots: %8.4f,%8.4f\n",-b/(2*a));
		}
		else
		{
			if(disc>1e-6)
			{
				x1 = (-b+sqrt(disc))/(2*a);

				x2 = (-b-sqrt(disc))/(2*a);

				printf("has two real roots:%8.4f,%8.4f\n",x1,x2);
			}
			else
			{
				realpart = -b/(2*a);
				imagpart = sqrt(-disc)/(2*a);
				printf("has two complex roots:\n");
				printf("%8.4f+%8.4fi\n",realpart,imagpart);
				printf("%8.4f-%8.4fi\n",realpart,imagpart);
			}
		}

	}
}