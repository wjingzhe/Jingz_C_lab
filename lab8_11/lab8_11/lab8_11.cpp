// lab8_11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

#include<stdio.h>
void main()
{
	float average(float array[10]);
	float score[10],aver;
	int i;
	printf("input 10 scores:\n");
	for(i=0;i<10;i++)
		scanf("%f",&score[i]);
	aver=average(score);
	printf("average score is %5.2f\n",aver);
}

float average(float array[10])
{
	int i;
	float aver,sum=0;
	for(i=0;i<10;i++)
		sum+=array[i];
	aver=sum/10;
	return aver;
}