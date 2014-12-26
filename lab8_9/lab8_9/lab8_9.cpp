// lab8_9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}
#include<stdio.h>
int static i=0;
void main()
{
	void hanoi(int n,char one,char two,char three);
	int m;
	printf("input the number of diskes:");
	scanf("%d",&m);
	printf("The step of moving %d diskes:\n",m);
	hanoi(m,'A','B','C');
}

void hanoi(int n,char one,char two,char three)
{
	void move(char x,char y);
	if(n==1)
	{
		move(one,three);
	}
	else
	{
		hanoi(n-1,one,three,two);
		move(one,three);
		hanoi(n-1,two,one,three);
	}
}

void move(char x,char y)
{
	printf("%c-->%c,i=%d\n",x,y,i);
	i++;
}