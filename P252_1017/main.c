#include <stdio.h>
#include <stdlib.h>

int man()
{
    char a[] = "I am a boy.i fear about my future.",b[50];
    int i = 0;
    for(i = 0;*(a+i)!='\0';i++)
    {
        *(b+i) = *(a+i);
    }
    *(b+i) = '\0';
    printf("string a is :%s\n",a);
    printf("string b is :");
    for(i = 0;b[i]!='\0';i++)
        printf("%c",b[i]);
    printf("\n");
    return 0;
}

int main()
{
    char a[] = "I am a boy.i fear about my future.",b[50];
    char *p1,*p2;
    p1 = a;
    p2 = b;
    int i;
    for(;*p1!='\0';p1++,p2++)
    {
        *p2 = *p1;
    }
    *p2 = '\0';
    printf("string a is :%s\n",a);
    printf("string b is :");
    for(i = 0;b[i]!='\0';i++)
        printf("%c",b[i]);
    printf("\n");
    return 0;
}
