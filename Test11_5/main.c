#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FORMAT "%d\t%s\t%f\t%f\t%f\t\n"
struct student
{
    int num;
    char name[20];
    float score[3];
};
int main()
{
    void print(struct student *p);
    struct student stu_1;
    stu_1.num = 12345;
    strcpy(stu_1.name,"Li Li");
    stu_1.score[0] = 67.5;
    stu_1.score[1] = 89;
    stu_1.score[2] = 78.6;
    print(&stu_1);
    return 0;
}
void print(struct student *p)
{
    printf(FORMAT,p->num,p->name,p->score[0],p->score[1],p->score[2]);

}
