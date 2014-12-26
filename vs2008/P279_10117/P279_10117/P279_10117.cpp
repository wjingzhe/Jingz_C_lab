// P279_10117.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define LENGTH 20
#define INCREMENT 10
int	t_main()
{
    int strcmp1(char *p1,char *p2);
    char *p1 = (char*)malloc(LENGTH*sizeof(char));
    char *p2 = (char*)malloc(LENGTH*sizeof(char));
    char c;
    int i = 0;
    printf("please intput first string\n");
    i = 0;
    while((c = getchar()) != '\0')
    {
        if(i>=LENGTH)
        {
            p1 = (char*)realloc(*p1,(LENGTH+INCREMENT)*sizeof(char));
            if(p1 == NULL) return -1;
        }
        *(p1+i) = c;
        i++;
    }
    *(p1+i) = '\0';
    printf("please intput second string\n");
    i = 0;
    while((c = getchar()) != '\0' && c != 13 && c != 12 )
    {
        if(i>=LENGTH)
        {
            p2 = (char*)realloc(*p2,(LENGTH+INCREMENT)*sizeof(char));
            if(p2 == NULL) return -1;
        }
        *(p2+i) = c;
        i++;
    }
    *(p1+i) = '\0';
    i = strcmp(p1,p2);

    switch(i)
    {
        case 1:
        printf("%s is bigger than %s",*p1,*p2);

        case -1:
        printf("%s is less than %s",*p1,*p2);

        case 0:
        printf("%s is equal to %s",*p1,*p2);
    }

    return 0;
}

int strcmp1(char *p1,char *p2)
{
    int i = strlen(*p1);
    int j = strlen(*p2);
    int k = 0;
    while(*p1 != '\0' && *p2 != '\0' && k < i && k < j)
    {
        if(*(p1+k) > *(p2+k)) return 1;
        else if(*(p1+k) < *(p2+k)) return 0;
        else k++;
    }

    if(k==i && k==j) return 0;
    else if(k >= i && k<j) return -1;
    else return 1;
}

