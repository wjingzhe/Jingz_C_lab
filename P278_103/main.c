#include <stdio.h>
#include <stdlib.h>

int main()
{
    void input(int *number);
    void output(int *number);
    void max_min_value(int *number);
    int number[10];
    input(number);
    max_min_value(number);
    output(number);
    return 0;
}

void input(int *number)
{
    int i = 0;
    printf("inout ten integer:");
    for(i = 0;i<10;i++)
    {
        scanf("%d",&number[i]);
    }
}

void output(int *number)
{
    int *p;
    printf("Now,they are:\n");
    for(p = number;p<number+10;p++)
    {
        printf("%d ",*p);
    }
    printf("\n");
}

void max_min_value(int *number)
{
    int *p,*max,*min;
    max = min = number;
    for(p = number+1;p<number+10;p++)
    {
        if(*max<*p) max = p;
        else if(*min>*p) min = p;
    }

    int temp;

    temp  = *min,*min = number[0],number[0] = temp;

    if(max==number) max = min;

    temp  = *max,*max = number[9],number[9] = temp;
}
