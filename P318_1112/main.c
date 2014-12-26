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
        printf("snum:");
        scanf("%ld",&p1->snum);
        printf("sname:");
        getchar();
        gets(p1->sname);
        printf("ssex:");
        scanf("%c",&p1->ssex);
        printf("sage:");
        scanf("%d",&p1->sage);
        if(i==0) {p2 = head = p1;}
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

STUDENT *converse(STUDENT *head)
{
    if((head==NULL) || (head->next == NULL)) return head;
    STUDENT *p1,*p2;
    p1 = NULL;
    while(head!=NULL)
    {
        p2 = head->next;
        head->next = p1;
        p1 = head;
        head = p2;
    }
    head = p1;
    return head;
}


int main()
{
    int n;
    printf("how many students' information you want to input:");//11Ã‚
    scanf("%d",&n);
    STUDENT *ahead = input_student(n);
    printf("These are students'informations:\n");
    print(ahead);
    ahead = converse(ahead);
    printf("These are students'informations concersed:\n");
    print(ahead);
    return 0;
}
