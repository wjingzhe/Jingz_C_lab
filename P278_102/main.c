#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    void swap(char *s1,char *s2);
    char str1[50],str2[50],str3[50];
    printf("input 1th string :\n");
    gets(str1);
    printf("input 2th string:\n");
    gets(str2);
    printf("input 3rd string:\n");
    gets(str3);
    if(strcmp(str1,str2)>0) swap(str1,str2);
    if(strcmp(str1,str3)>0) swap(str1,str3);
    if(strcmp(str2,str3)>0) swap(str2,str3);

    printf("Now,the order is:\n");
    printf("%s\n%s\n%s\n",str1,str2,str3);

    return 0;
}




void swap(char *s1,char *s2)
{
    char p[50];
    strcpy(p,s1);
    strcpy(s1,s2);
    strcpy(s2,p);
}
