#include <stdio.h>
#include <stdlib.h>
#define NEWSIZE 1000
char newbuf[NEWSIZE];
char *newp = newbuf;

char * new(int n)
{
    if(newp+n<=newbuf+n)
    {
        newp = newp + n;
        return(newp-n);
    }
    else
        return NULL;
}

free(char *p)
{
    if((p>=newbuf)&&(p<newbuf+NEWSIZE))
    {
        newp = p;
    }
}
int main()
{
    int n = 100;
    char *p;
    p = new(n);
    free(p);
    return 0;
}
