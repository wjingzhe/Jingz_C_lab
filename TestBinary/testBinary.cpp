#include <stdio.h>
struct s1
{
//	int i:8;
//int j: 4;
//int a: 3;
double b;
};

struct s2
{
int i: 8;
int j: 4;
double b;
int a:3;
};

void main()
{
	printf("sizeof(s1)= %d\n", sizeof(s1));
	printf("sizeof(s2)= %d\n", sizeof(s2));
	getchar();
}