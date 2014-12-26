#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float integral(float(*p)(float),float a,float b,int n);
    float fsin(float x);
    float fcos(float x);
    float fexp(float x);

    float a1,b1,a2,b2,a3,b3,c,(*p)(float);
    int n;
    printf("Input the num:");
    scanf("%d",&n);
    printf("input a1,b1:");
    scanf("%f,%f",&a1,&b1);
    printf("input a2,b2:");
    scanf("%f,%f",&a2,&b2);
    printf("input a3,b3:");
    scanf("%f,%f",&a3,&b3);

    p = fsin;
    c = integral(p,a1,b1,n);//求出sin（n）的定积分
    printf("The integral of sin(n) is :%f\n",c);

    p = fcos;
    c = integral(p,a2,b2,n);//求出cos（n）的定积分
    printf("The integral of cos(n) is :%f\n",c);

    p = fexp;
    c = integral(p,a3,b3,n);//求出exp（n）的定积分
    printf("The integral of exp(n) is :%f\n",c);

    return 0;
}

float integral(float(*p)(float),float a,float b,int n)
{
    int i;
    float x,h,s;
    h = (b-a)/n;
    x = a;
    s = 0;
    for(i = 1;i<=n;i++)
    {
        x = x+h;
        s = s+(*p)(x)*h;
    }

    return s;
}

float fsin(float x)
{
    return sin(x);
}

float fcos(float x)
{
    return cos(x);
}

float fexp(float x)
{
    return exp(x);
}
