//jobFcfs.c
#include"stdio.h"
#include<stdlib.h>
#include<conio.h>
#define getpcb(type) (type*)malloc(sizeof(type))
#define getjob(type) (type*)malloc(sizeof(type))
struct job { /* 定义作业控制块job */ 
    char name[10]; 
    char state; /*状态   */
	int super;/*优先级*/
    int ntime;  /*需要的运行时间  */
    int rtime;  /*已执行的时间 */
}*j; /*ready为就绪队列，p指向现在操作的作业进行操作*/

typedef struct job JOB;

int jInput() /* 建立作业列表函数*/ 
{ 
    int i,num;
    printf("\n 请输入作业个数：");
    scanf("%d",&num);
    for(i=0;i<num;i++) 
    { 
		j=getjob(JOB);
		char chEnter,filename[10];
		scanf("%s",filename);
		job work;
        printf("\n 作业号No.%d:\n",i); /*输入要插入的作业信息*/
        printf("\n 输入作业名:"); 
        scanf("%s",&j->name); 
		chEnter=getch();
        printf("\n 输入优先级");
		scanf("%d",&j->super);
        printf("\n 输入作业运行时间:"); 
        scanf("%d",&j->ntime); 
        printf("\n"); 
        j->rtime=0;j->state='w';
        insert(); /* 调用insert函数把输入的作业插入到队列后面*/
		return 0;
    } 
}

int jInsert()/*刚开始时插入要构造的作业*/
{
	FILE *fp;
    if((fp=fopen(filename,"ab+"))==NULL)
		{
			printf("无法打开文件");
			exit();
		}
	chEnter=getch();
	fwrite(p,sizeof(pcb),1,fp);
	fclose(fp);
	return 0;

}

int jDisp(JOB * jr) /*建立作业显示函数,用于显示当前作业*/ 
{ 
	static job i;
    printf("\nqname\tstate\tndtime\truntime\n");
	if((fp1=fopen(filename,"rb+"))==NULL)
		{
			printf("无法打开文件");
			exit();
		}
	chEnter=getch();
	fseek(fp1,i,0);
	fread(jr,sizeof(jcb),1,fp1);
    printf("%s\t",jr->name); 
    printf("|%c\t",jr->state); 
    printf("|%d\t",jr->ntime); 
    printf("|%d\t",jr->rtime); 
    printf("\n"); 
	fclose(fp);
	i++;
}


int jCheck() /* 建立作业查看函数 */ 
{ 
    JOB* jr; 
    printf("\n **** 当前正在运行的进程是:%s",p->name); /*显示当前运行作业*/ 
	pr=getjob();
	jDisp(p); 
	free(jr)；
} 


 int jDestroy() /*建立作业撤消函数(进程运行结束,撤消进程)*/ 
{ 
    printf("\n 作业 [%s] 已完成.\n",p->name); 
}

int  jRun() /* 建立作业就绪函数(作业运行时间到,置就绪状态*/ 
{ 
    jDestroy(); /* 调用destroy函数*/ 
    
} 


typedef struct pcb PCB;
input() /* 建立进程控制块函数*/ 
{
	static int h=0;
    printf("\n 进程号No.%d:\n",h); /*执行进程的信息*/
    p=getpcb(PCB); 
	p=j;
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
    } 
} 


destroy() /*建立进程撤消函数(进程运行结束,撤消进程)*/ 
{ 
    printf("\n 进程 [%s] 已完成.\n",p->name); 
    free(p); 
}

run() /* 建立进程就绪函数(进程运行时间到,置就绪状态*/ 
{ 
    destroy(); /* 调用destroy函数*/ 
	k++
} 

int pmain()
{
	int len;
    char ch; 
    input(); /*输入进程数*/
    while(ready!=NULL)/*当队列不为空时就循环进行调度*/
    { 
        h++; 
        printf("\n\n The execute number:%d \n",h); 
        input()
        check(); 
        run(); 
        printf("\n 按任一键继续......"); 
        ch=getchar(); 
    } 
    printf("\n\n 进程已经完成.\n"); 
}

int main()/*主函数*/
{
    int len,h=0;
    char ch5,ch6; 
    input(); /*输入作业数*/
    while(1)/*当队列不为空时就循环进行调度*/
    { 
        
        pmain();
		if((ch6=='Y')||(ch6=='y'))
		{
			exit(0);
		}
    } 
}

