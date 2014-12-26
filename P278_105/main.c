#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[100],i,k,m,n,*p;
    printf("input number of person:n=");
    scanf("%d",&n);
    p = num;

    for(i = 0;i<n;i++)
    {
        *(p+i) = i+1;
    }
    i = 0;
    k = 0;
    m = 0;
    while(m<n-1)
    {
        if(*(p+i)!=0) k++;
        if(k == 3)
        {
            *(p+i) = 0;
            k = 0;
            m++;
        }
        i++;
        if(i==n) i=0;

    }

    while(*p==0) p++;
    printf("The lasr one is No.%d\n",*p);
    return 0;
}
