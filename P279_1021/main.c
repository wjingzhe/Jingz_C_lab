#include <stdio.h>
#include <stdlib.h>

int main()
{
    void sort(int * * p,int n);
    int i,n=0,digit[20];
    int * *p,*pstr[20];
    printf("please input n:\n");
    scanf("%d",&n);
    while(n<=0||n>20)
    {
        printf("n is elligal,please input another:\n");
        scanf("%d",&n);
    }
    printf("input %d integer numners:\n",n);
    for(i = 0;i < n;i++)
    {
        pstr[i] = &digit[i];
        scanf("%d",pstr[i]);
    }
    p = pstr;

    sort(p,n);
    printf("Now,the sequence is:\n");
    for(i = 0;i < n;i++)
    {
        printf("%d ",*pstr[i]);
    }
    printf("\n");
    return 0;
}

void sort(int * * p,int n)
{
    int * temp;
    int i,j;
    for(i = 0;i < n;i++)
    {
        for(j = i+1;j < n;j++)
        {
            if(**(p+i)>**(p+j))
            {
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }//if
        }//for_j
    }//for_i
}//sort
