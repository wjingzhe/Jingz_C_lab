#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define LEN sizeof(struct student)

struct student
{
    long num;
    float score;
    struct student *next;
};
int n;

struct student* creat(void)
{
    struct student *head;
    struct student *p1,*p2;
    n = 0;
    p1 = p2 =(struct student *)malloc(LEN);/*开辟一个新单元*/
    head = NULL;
    while(n<3)
    {
        n++;
        scanf("%ld,%f",&p1->num,&p1->score);
        if(n==1) head = p1;
        else p2->next = p1;
        p2 = p1;
        p1 =(struct student *)malloc(LEN);/*开辟一个新单元*/

    }
    p2->next = NULL;
    return head;
}

void print(struct student *head)
{
    struct student *p;
    printf("\nNow,these %d recoeds are:\n",n);
    p = head;
    while(p!=NULL)
    {
        printf("%ld,%f\n",p->num,p->score);
        p = p->next;
    }
}

struct student *del(struct student *head,long num)
{
    if(head==NULL) {printf("\nlist null! \n");return head;}
    struct student *p1,*p2;
    p2 = p1 = head;
    while(p1!=NULL&&num!=p1->num)
    {
        p2 = p1;
        p1 = p1->next;
    }//while
    if(p1==head)//删除首元素
    {
        head = p1->next;
        free(p1);
    }
    else if(p1==NULL)//找不到该元素
    {
        printf("Can't find the student whose number is %ld\n",num);
    }
    else//普通删除
    {
        p2->next = p1->next; //如果删除的是尾结点，则p1->next==NULL,所以跟普通删除处理过程是一样的
        free(p1);
    }
    return head;
}//del

struct student *insert(struct student *head,struct student *stud)
{
    if(head==NULL) {printf("\nlist null! \n");return head;}
    struct student *p0,*p1,*p2;
    p2 = p1 = head;
    p0 = stud;
    while(p1!=NULL&&p1->num<p0->num)
    {
        p2 = p1;
        p1 = p1->next;
    }

    if(p1==NULL)//插入到链表尾端
    {
        p2->next = p0;
        p0->next = NULL;
    }
    else if(p1==head)//p1->num>=p0->num，将p0插入首元素之前
    {
        p0->next = head;
        head = p0;
    }
    else
    {
        p2->next = p0;
        p0->next = p1;

    }//if_else_if
    n++;
    return head;
}


int main()
{
    struct student *head,stu;
    long del_num;
    printf("input records:\n");
    head = creat();  /* 建立链表，返回头指针 */
    print(head); /* 输出链表 */
    printf("\ninput the deleted number:");
    scanf("%ld",&del_num);/*输入要删除的学生号*/
    head = del(head,del_num);/*删除后链表的地址*/
    print(head);
    printf("\ninput the inserted:");/*输入要插入的结点*/
    scanf("%ld,%f",&stu.num,&stu.score);
    head = insert(head,&stu);
    print(head);

    return 0;
}
