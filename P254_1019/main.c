#include <stdio.h>
#include <stdlib.h>

int main()
{
    void copyString(char *a,char *b);
    char a[] = "I am a teacher.";
    char b[] = "You are a student.";
    copyString(a,b);
    printf("String a is %s\n",a);
    printf("String b is %s\n",b);
    return 0;
}

void copyString(char *a,char *b)
{
    while(*a!='\0')
    {
     *b++ = *a++;
    }
   *b = '\0';
}
