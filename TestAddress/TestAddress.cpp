#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void s(int*(a))
{
    free(a);
	a = 0;
}

int main()
{
	int *a = (int *)malloc(sizeof(int));
	int b[1];
	b[0] = 100;
	a = b;
	s(a);
	printf("%d  \n",a);
	return 1;

}



