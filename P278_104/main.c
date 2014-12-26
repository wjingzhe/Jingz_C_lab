#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloc.h>

int main()
{
    void move(int array[20],int n,int m);
    int number[20],n,m,i;
    printf("How many numbers?");
    scanf("%d",&n);
    printf("input %d number:\n",n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&number[i]);
    }
    printf("how many place you want move?");
    scanf("%d",&m);

    move(number,n,m);
    printf("Now,they are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",number[i]);
    }
    printf("\n");
    return 0;
}
/*
void move(int array[20],int n,int m)
{
    int *p,array_end;
    array_end = *(array+n-1);
    for(p = array+n-1;p>array;p--)
    {
        *p = *(p-1);
    }
    *array = array_end;
    m--;
    if(m>0) move(array,n,m);
}
*/

void move(int array[],int n,int m)
{
    int *p,*q,i = 0;
    q = (int *)alloc(sizeof(int)*m);
    strcpy(q,array[n-m]);
    for(p = &array[n-1-m];p>=array[m];p--)
    {
        *p = *(p-m);
    }
    int temp = array[m];
    strcpy(array,q);
    array[m] = temp;
}//move

