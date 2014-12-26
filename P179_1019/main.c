#include <stdio.h>
#include <stdlib.h>

//#define NULL 0 /* 当开辟失败时返回标志 */
#define ALLOCSIZE 1000 /* 最大开辟存取 */
char *alloc(int n);
void free1(char *p);
char allocbuf[ALLOCSIZE]; /* 开辟一个内存区，完成由c编译系统使用数组内存开辟函数完成*/
char *allocp = allocbuf; /* 指针指向第一个可存区的始端 */
int main()
{

    char *c = alloc(3);
    printf("%ld\n",c);
    free(c);
    return 0;
    printf("%ld\n",c);
}

char *alloc(int n)
{
    if(allocp+n <= allocp+ALLOCSIZE)
    {
        allocp += n;
        return allocp-n;
    }
    else
        return(NULL);
}

void free1(char *p)
{
    if(p>=allocbuf&&p<allocbuf+ALLOCSIZE)
        allocp = p;
}
