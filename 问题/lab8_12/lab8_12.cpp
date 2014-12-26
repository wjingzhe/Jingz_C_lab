#include<stdio.h>
void main()
{
	float average(float arr[],int n);
	float score_1[5]={98.5,97,91.5,60,55};
	float score_2[10]={67.5,89.5,99,69.5,77,89.5,76.5,54,60,99.5};
	printf("the average of class A is %6.2f\n",average(score_1,5));
	printf("the average of class B is %6.2f\n",average(score_2,10));
}

float averge(float arr[],int n)
{
	int i;
	float aver,sum=arr[0];
	for(i=1;i<n;i++)
		sum+=arr[i];
	aver=sum/n;
	return aver;
}

