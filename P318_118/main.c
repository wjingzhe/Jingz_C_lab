#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define LEN sizeof(STUDENT)
#define STU STUDENT
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

STUDENT * create(int n)
{
    STUDENT *p1,*p2,*head;
    int i = 0;
    for(i = 0;i < n;i++)
    {
        printf("input the %d students' info:\n",i+1);
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
}//create

STUDENT * sort(STUDENT *head)
{
    STU *p0,*p1,*p2,*temp;
    p1 = head;
    p0 = temp = p1;
    while(p1 != NULL)
    {
        temp = p2 = p1->next;
        while(p2 != NULL)
        {
            if(p1->snum >= p2->snum)
            {
                if(head==p1)
                {
                    head = p1->next;
                    p1->next = p2->next;
                    p2->next = p1;
                }
                else
                {
                    p0->next = p1->next;
                    p1->next = p2->next;
                    p2->next = p1;

                }//if_head_else
                /* if exchanged p0 should be renewed as pointing p2 whose next is p1 */
                p0 = p2;
                p2 = p1->next;
            }
            else
            {
               p2 = p2->next;
            }
        }//while_p2
        p1 = temp;
        if(p1==head) p0 = p1;
        else
        {
            p0 = head;
            while(p0->next!=p1) p0 = p0->next;
        }
    }//while_p1
    return head;
}//sort

STUDENT *concatList(STUDENT *ahead,STUDENT *bhead)//升序排列
{
    STUDENT *p,*pa,*pb;
    if(ahead==NULL) return bhead;
    else if(bhead==NULL) return ahead;
    else if(ahead->snum <= bhead->snum)//将ahead和bhead指向同一个结点，用于函数返回值，p、pa、pb用于遍历操作
    {
        pa = ahead->next;
        pb = bhead;
        bhead = p = ahead;
    }
    else
    {
        pa = ahead;
        pb = bhead->next;
        ahead = p = bhead;
    }

    while(pa&&pb)
    {
        if(pa->snum <= pb->snum)
        {
            p->next = pa;
            p = pa;
            pa = pa->next;
        }
        else
        {
            p->next = pb;
            p = pb;
            pb = pb->next;
        }
    }//while_pa&&pb
    p->next = pa?pa:pb;

    return ahead;
}//concatList

int main()
{
    int n;
    printf("In LIST_a how many student nodes you want to create?\n");
    scanf("%d",&n);
    STUDENT *ahead = sort(create(n));
    printf("In LIST_b how many student nodes you want to create?\n");
    scanf("%d",&n);
    STUDENT *bhead = sort(create(n));
    ahead = concatList(ahead,bhead);
    printf("New List is :\n");
    print(ahead);
    return 0;
}
