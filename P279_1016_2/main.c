#include <stdio.h>
#include <stdlib.h>

/*
Last time i can't understand the codes in the book of answers.
Today i read it again,and i did.
Just because of teaching the knowledge of pointer to us,the answer in the book used a lot of pointer and variable,Although solving a simple quetion.
Now today i try to show it to my readers,some greenhands.
I will explain the complicated codes which are hard to anderstand.
*/

int main()
{
    char str[50],*pstr;//在本章作者很喜欢用同含义不同名的变量指向同一数据。
    int i,j,k,m,e10,digit,ndigit,a[10],*pa;
    printf("input a string:\n");
    gets(str);//这个语句很容易出现溢出问题，字符串会被截断，即便是平时作业都不喜欢用它
    pstr = &str[0];//字符指针pstr置于数组str首地址
    pa = &a[0];//指针pa置于数组a的首地址
    ndigit = 0;
    i = 0;
    j = 0;

    while(*(pstr+i)!='\0')//未到字符串结尾
    {
        if(*(pstr+i)>='0'&&*(pstr+i)<='9')
            j++;    //是数字则记录
        else
        {
            if(j>0) //j>0则是由数字字符，否则是连续的其他字符直接跳过即可
            {
                digit = *(pstr+i-1)-48;//从i-1位开始逆溯知道滴i-1-j个字符都是数字字符，先把各位赋值给digit
                k = 1;
                while(k<j)//将剩余位的数字字符累计于digit上
                {
                    e10 = 1;
                    for(m = 1;m<=k;m++)
                        e10 = e10*10;//e10表示该位所乘因子

                    digit = digit + (*(pstr+i-1-k)-48)*e10;//字符换算成数字

                    k++;
                }//while
                *pa = digit;
                pa++;
                ndigit++;
                j = 0;
            }//if

        }//if_else

        i++;//每次读取一个新字符
    }//while

    if(j>0)//处理字符串以数字字符结尾的情况,每次出现同样代码时候就应该考虑算法是否合理。显然是可以修改的。可参照上一篇代码
    {
        digit = *(pstr+i-1)-48;
        k = 1;
        while(k<j)//将剩余位的数字字符累计于digit上
        {
            e10 = 1;
            for(m = 1;m<=k;m++)
                e10 = e10*10;//e10表示该位所乘因子

            digit = digit + (*(pstr+i-1-k)-48)*e10;//字符换算成数字

            k++;
        }//while
        *pa = digit;
        ndigit++;
        j = 0;
    }//if

    printf("There are %d numbers in this line.They are :\n",ndigit);
    j = 0;
    pa = &a[0];
    for(j = 0;j<ndigit;j++)
        printf("%d ",*(pa+j));
    printf("\n");

    return 0;
}
