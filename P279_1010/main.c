#include <stdio.h>
#include <stdlib.h>

int main()
{
    void change(int *);

    int a[5][5],*p,i,j;
    printf("Input the matrix:\n");
    for(i = 0;i<5;i++)          //输入矩阵
        for(j = 0;j<5;j++)
        {
            scanf("%d",&a[i][j]);
        }

    p = &a[0][0];
    change(p);
    printf("Now,the matrix is :\n");

    for(i = 0;i<5;i++) //输出矩阵
    {
        for(j = 0;j<5;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}//main


void change(int *p)
{
    int i,j,temp,k;
    int *pmax,*pmin;
    pmax = p;
    pmin = p;
    for(i = 0;i<5;i++)    //寻找最大值和最小值的地址，并赋给pmax，pmin
    {
        for(j = 0;j<5;j++)
        {
            if(*pmax<*(p+5*i+j)) pmax = p+5*i+j;
            if(*pmin>*(p+5*i+j)) pmin = p+5*i+j;
        }
    }

    //最大值换给中心元素
    temp = *(p+12);
    *(p+12) = *pmax;
    *pmax = temp;

    //最小值换给中心元素
    temp = *pmin;
    *pmin = *p;
    *p = temp;

    //寻找第二小值地址赋给pmin
    pmin = p+1;//还原指针pmin的位置，指向矩阵第一行第二列元素

    for(i = 0;i<5;i++)    //寻找第二小值的地址，赋值pmin
    {
        if(i==0) j = 1;
        else j = 0;
        for(;j<5;j++)
        {
            if(*pmin>*(p+5*i+j)) pmin = p+5*i+j;
        }
    }
    temp = *pmin;
    *pmin = *(p+4);
    *(p+4) = temp;

    pmin = p+1;//还原指针pmin的位置，指向矩阵第一行第二列元素

    for(i = 0;i < 5;i++)    //寻找第三小值的地址，并赋给pmin
    {
        if(i == 0) {j = 1,k = 4;}
        else {j = 0,k = 5;}
        for(;j < k;j++)
        {
            if(*pmin > *(p+5*i+j)) pmin = p+5*i+j;
        }
    }//for
    temp = *pmin;
    *pmin = *(p+20);
    *(p+20) = temp;

    pmin = p+1;//还原指针pmin的位置，指向矩阵第一行第二列元素

    for(i = 0;i < 5;i++)    //寻找第四小值的地址，并赋给pmin
    {
        if(i == 0) {j = 1,k = 4;}
        else if(i == 4) {j = 1,k = 5;}
        else {j = 0,k = 5;}
        for(;j < k;j++)
        {
            if(*pmin > *(p+5*i+j)) pmin = p+5*i+j;
        }
    }//for
    temp = *pmin;
    *pmin = *(p+24);
    *(p+24) = temp;
}//change
