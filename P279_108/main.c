#include <stdio.h>
#include <stdlib.h>

int main()
{
    int upper = 0,lower = 0,digit = 0,space = 0,other = 0,i = 0;
    char *p,s[20];
    printf("input string: ");
    while((s[i]= getchar())!='\n') i++;

    p = &s[0];

    while(*p != '\n')
    {
        if(('A'<=*p)&&(*p<='Z'))
            upper++;
        else if(('a'<=*p)&&(*p<='z'))
            lower++;
        else if(('0'<=*p)&&(*p<='9'))
            digit++;
        else if(' '==*p)
            space++;
        else other++;

        p++;
    }

    printf("upper case:%d    lower case:%d   digit case:%d  space case:%d   other case:%d\n",upper,lower,digit,space,other);
    return 0;
}
