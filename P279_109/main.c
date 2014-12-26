#include <stdio.h>
#include <stdlib.h>

int main()
{
    void move(int *pointer);
    int a[3][3],*p,i;
    printf("input the matrix:\n");
    for(i = 0;i<3;i++)
    {
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    }
    p = &a[0][0];
    move(p);
    printf("Now,matrix:\n");
    for(i = 0;i<3;i++)
    {
        printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
    }
    return 0;
}

void move(int *p)
{
    int i,j,t;
    for(i = 0;i<3;i++)
    {
        for(j = 0;j<i;j++)
        {
            t = *(p+i*3+j);
            *(p+i*3+j) = *(p+j*3+i);
            *(p+j*3+i) = t;
        }
    }
}
