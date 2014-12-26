//timepiece.c
#include "stdio.h"
#define getpch(type) (type*)malloc(sizeof(type)) 


struct pcb { /* 定义进程控制块PCB */ 
    char name[10]; 
    char state; /*状态   */
    int ntime;  /*需要的运行时间  */
    int rtime;  /*已执行的时间 */
    struct pcb* link; /*下一个进程控制块的地址 */
    }*ready=NULL,*p; /*ready为就绪队列，p指向现在操作的进程进行操作*/

typedef struct pcb PCB;

insert()/*刚开始时插入要构造的进程*/
{
    PCB *cur=ready,*nextpcb;
    if(ready==NULL)/*就绪队列为空时，即插入第一个进程时*/
        ready=p;
    else/*就绪队列不为空*/
    {
		nextpcb=ready->link;
        while(nextpcb!=NULL)/*找到队列的最后位置*/
        {
            cur=nextpcb;
            nextpcb=nextpcb->link;
        }
        cur->link=p;/*把进程插入到队列最后*/

    }

}

input() /* 建立进程控制块函数*/ 
{ 
    int i,num;
    printf("\n 请输入进程个数：");
    scanf("%d",&num);
    for(i=0;i<num;i++) 
    { 
        printf("\n 进程号No.%d:\n",i); /*输入要插入的进程的信息*/
        p=getpch(PCB); 
        printf("\n 输入进程名:"); 
        scanf("%s",p->name); 
        printf("\n 输入进程运行时间:"); 
        scanf("%d",&p->ntime); 
        printf("\n"); 
        p->rtime=0;p->state='w'; 
        p->link=NULL; 
        insert(); /* 调用insert函数把输入的进程插入到队列后面*/
    } 
}


disp(PCB * pr) /*建立进程显示函数,用于显示当前进程*/ 
{ 
    printf("\nqname\tstate\tndtime\truntime\n");
    printf("%s\t",pr->name); 
    printf("|%c\t",pr->state); 
    printf("|%d\t",pr->ntime); 
    printf("|%d\t",pr->rtime); 
    printf("\n"); 
}


check() /* 建立进程查看函数 */ 
{ 
    PCB* pr; 
    printf("\n **** 当前正在运行的进程是:%s",p->name); /*显示当前运行进程*/ 
    disp(p); 
    pr=ready; 
    printf("\n ****当前就绪队列状态为:\n"); /*显示就绪队列状态*/ 
    while(pr!=NULL) 
    { 
        disp(pr); 
        pr=pr->link; 
    } 
} 


destroy() /*建立进程撤消函数(进程运行结束,撤消进程)*/ 
{ 
    printf("\n 进程 [%s] 已完成.\n",p->name); 
    free(p); 
}

run() /* 建立进程就绪函数(进程运行时间到,置就绪状态*/ 
{ 
    (p->rtime)++; 
    if(p->rtime>=p->ntime) 
        destroy(); /* 调用destroy函数*/ 
    else 
    { 
        p->state='w'; 
        insert(); /*调用insert函数*/
    } 
} 


main()/*主函数*/
{
    int len,h=0;
    char ch; 
    input(); /*输入进程数*/
    while(ready!=NULL)/*当队列不为空时就循环进行调度*/
    { 
        h++; 
        printf("\n The execute number:%d \n",h); 
        p=ready; 
        ready=p->link; 
        p->link=NULL; 
        p->state='R'; 
        check(); 
        run(); 
        printf("\n\n 按任一键继续......"); 
        ch=getchar(); 
    } 
    printf("\n\n 进程已经完成.\n"); 
}
