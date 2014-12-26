#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct person
{
    char name[20];
    int count;
}leader[3] = {{"Li",0},{"Zhang",0},{"Fun",0}};

int main()
{
    int i,j;
    char leader_name[20];//¼ÇÆ±»º´æ

    for(i = 0;i < 10;i++)
    {
        scanf("%s",leader_name);
        for(j = 0;j < 3;j++)
        {
            if(strcmp(leader_name,leader[j].name) == 0)
            {
                leader[j].count++;
            }
        }//for_j
    }//for_i

    printf("\n");
    for(i = 0;i < 3;i++)
        printf("%5s:%d\n",leader[i].name,leader[i].count);

    return 0;
}
