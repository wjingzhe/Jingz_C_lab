#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    void copyStr(char *str1,char *str2,int m);
    int m;
    char str1[20],str2[20];
    printf("Input string:");
    gets(str1);
    printf("which character that begin to copy?");
    scanf("%d",&m);
    if(strlen(str1)<m)
        printf("Input error!");
    else
    {
        copyStr(str1,str2,m);
        printf("result:%s\n",str2);
    }

    return 0;
}


void copyStr(char *str1,char *str2,int m)
{
    int n = 0;

    while(n<m-1)
    {
        str1++;
        n++;//寻找到复制开始位置
    }
    while(*str1!='\0')
    {
        *str2 = *str1;
        str1++;
        str2++;
    }
    *str2 = '\0';
}
