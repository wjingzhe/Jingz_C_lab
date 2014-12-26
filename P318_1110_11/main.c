#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define LEN sizeof(STUDENT)

typedef struct
{
    long snum;
    char sname[10];
    char ssex;
    int sage;
    struct STUDENT *next;
}STUDENT;

void print(STUDENT *head)
{
    STUDENT *p1;
    p1 = head;
    while(p1!=NULL)
    {
        printf("snum:%ld",p1->snum);
        printf("\nsname:");
        puts(p1->sname);
        printf("ssex:%c",p1->ssex);
        printf("\nsage:%d\n",p1->sage);
        p1 = p1->next;
    }
}

STUDENT * input_student(int n)
{
    STUDENT *p1,*p2,*head;
    int i = 0;
    for(i = 0;i < n;i++)
    {
        p1 = (STUDENT *)malloc(LEN);
        printf("Please input %dth' information\n",i+1);
        printf("snum:");
        scanf("%ld",&p1->snum);
        printf("sname:");
        getchar();
        gets(p1->sname);
        printf("ssex:");
        scanf("%c",&p1->ssex);
        printf("sage:");
        scanf("%d",&p1->sage);
        if(i==0) p2 = head = p1;
        else
        {
            p2->next = p1;
            p2 = p2->next;
        }
        p1 = (STUDENT *)malloc(LEN);
    }//for
    p2->next = NULL;
    free(p1);
    return head;
}

STUDENT *delete_sage(STUDENT *head,int n)
{
    STUDENT *p1,*p2;
    p1 = p2 = head;
    if(head->sage==n)
    {
        p1 = head;
        head = head->next;
        free(p1);
        return head;
    }
    else
    {
        p1 = head->next;
        p2 = head;
        while(p1!=NULL)
        {
            if(p1->sage==n)
            {
                p2->next = p1->next;
                free(p1);
                return head;
            }
            else
            {
                p2 = p1;
                p1 = p1->next;
            }
        }//while
    }
    printf("Not found students whose age is %d\n",n);
    return head;
}

STUDENT *delete_stu(STUDENT *ahead,STUDENT *bhead)
{
    STUDENT *p1,*p2,*p3;
    p3 = bhead;
    while(p3!=NULL)
    {
        p1 = p2 = ahead;
        if(ahead->snum==p3->snum)
        {
            p1 = ahead;
            ahead = ahead->next;
            free(p1);
            p3 = p3->next;
            continue;
        }
        else
        {
            p1 = ahead->next;
            p2 = ahead;
            while(p1!=NULL)
            {
                if(p1->snum==p3->next)
                {
                    p2->next = p1->next;
                    free(p1);
                    break;
                }
                else
                {
                    p2 = p1;
                    p1 = p1->next;
                }
            }//while_p1
        }//if_else

        p3 = p3->next;
    }//while_p3

    return ahead;
}

int main()
{
    int n;
    printf("how many students' information you want to input:");//11Ã‚
    scanf("%d",&n);
    STUDENT *ahead = input_student(n);
    printf("These are students'informations:\n");
    print(ahead);
    printf("input the age that you want delete students whose age is:");
    printf("These are students'informations:\n");
    scanf("%d",&n);
    ahead = delete_sage(ahead,n);
    print(ahead);

    //10Ã‚
    printf("how many students' information you want to delete:");
    scanf("%d",&n);
    STUDENT *bhead = input_student(n);
    ahead = delete_stu(ahead,bhead);
    printf("These are students'informations:\n");
    print(ahead);


    return 0;
}
