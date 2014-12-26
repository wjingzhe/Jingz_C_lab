#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define getjcb(type) (type*)malloc(sizeof(type))
//#define NULL 0
 int j=0;
int n,i;           //需要输入的作业数量
float T1=0,T2=0;  //初始化周转时间,带权周转时间.
int times=0;      //初始化开始运行时间
int freemem=100,taple=5;   //预定内存的大小为100k,taple数量为5个.

struct jcb      //作业控制块
{
 char username[10];   //用户名
 char name[10];  //作业名
 int reachtime;   //作业到达时间
 int starttime;    //作业开始时间
 int runtime;    //已经运行了的时间
 int needtime;       //作业需要运行的时间
 int freem;       //作业要占用的内存
 int taples;    //作业所需taple 
 int finishtime;       //作业完成时间
 //float cycletime;       //作业周转时间
 //float cltime;           //作业带权周转时间
 char state;            //作业状态
 struct jcb *next;      //结构体指针
}*ready=NULL,*start=NULL,*p,*q,*r,*s,*t;
typedef struct jcb JCB;



void inital()           //建立作业控制块队列,先将其排成先来先服务的模式队列
{
	int i;
	printf("\n输入作业数:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p=getjcb(JCB);
		printf("\n输入用户名:");
		scanf("%s",p->username);
		printf("输入作业名:");
		scanf("%s",p->name);
		p->reachtime=i;
		printf("作业默认到达时间:%d",i);
		printf("\n输入作业要运行的时间:");
		scanf("%d",&p->needtime);
		printf("输入作业运行要占用的内存:");
		scanf("%d",&p->freem);
		if(p->freem>freemem)
		{
			printf("请重新输入作业运行要占用的合理内存:");
			scanf("%d",&p->freem);
		}
		printf("输入作业运行所需taple :");
		scanf("%d",&p->taples);
		if(p->taples>taple)
		{
			printf("taple不足，请重新输入（0-5）:");
			scanf("%d",&p->taples);
		}
		p->runtime=0;
		p->state='W';
		p->next=NULL;
		if(ready==NULL)  ready=q=p;    //先将其按到达的先后顺序排成后备序列
		else{
			q->next=p;
			p->next=NULL;
			q = p; 
		}
	}
}

int count()     //计算内存中作业的个数
{
int i=0; JCB* pr=start;
while(pr!=NULL)
{
i++;
pr=pr->next;
}
return(i);
}


void apply()             //把符合条件的作业调用内存,并给他们分配资源,
{
  int len;
  p=ready;
  while(p!=NULL)
    {

        if((p->freem<=freemem)&&(p->taples<=taple))
        {
            freemem-=p->freem;
            taple-=p->taples;
            r=p;
            p=p->next;
            
            if(r==ready)          //先将符合条件的就绪作业从后备队列中分离出来
            {
                ready=r->next;
                r->next=NULL;
            }
            else
            {
                q=ready;
                while(q->next!=r)  
				{q=q->next;}
                q->next=r->next;
            }
            if(start==NULL)  {start=s=r;}        // 将其插到start队列,
            else
			{
               	s->next=r;
				r->next=NULL;
				s=r;
            }
        }
        else
        {
            p=p->next;

        }
    }
   len=count();
    printf("\n\t此时有%d道作业在内存\n\n",len);
}


void disp(JCB * pr) /*建立作业显示函数  */

{
printf("|%s\t",pr->username);
printf("|%s\t",pr->name);
printf("|%c\t",pr->state);
printf("|%d\t",pr->reachtime);
printf("|%d\t",pr->needtime);
printf("|%d\t",pr->runtime);
printf("|%d\t",pr->freem);
printf("|%d\t",pr->taples);
printf("\n");

}





void check()      //显示作业状况
{

    printf("\n作业%s于完成%d个作业后运行完毕,其完成后的情况:",q->name,j);
    j++;
    printf("\n用户名--作业名--状态--到达时间-需运时-已运时-需占内存-需taple 数量 \n");
    disp(q);
    s=start;
    printf("\n\t\t---------当前进入内存的作业状态---------");
    printf("\n用户名--作业名--状态--到达时间-需运时-已运时-需占内存-需taple 数量 \n");
	if(s==NULL)
	{s=start;}
	else 
	{
		while(s->next!=NULL)
		{
			disp(s);
			s=s->next;
		}
	}
	disp(s);
    r=ready;
    printf("-\n\n\t\t---------当前后备作业表中作业的状态----------");
    printf("\n用户名--作业名--状态--到达时间-需运时-已运时-需占内存-需taple 数量 \n");
    while(r!=NULL)
   {
     disp(r);
     r=r->next;
   }
}

                
                
void running()         //运行作业
{
    for(t=start;t!=NULL;)
    {
        start=t->next;
        q=t;
        q->next=NULL;
        q->state='R';
        q->runtime++;
        t=start;
        times++;
        if(q->runtime==q->needtime)
        {
            q->finishtime=times;
            q->starttime=q->finishtime-q->needtime;
           // q->cycletime=(float)q->finishtime-q->reachtime;
           // q->cltime=(q->cycletime)/(q->needtime);
           // T1+=q->cycletime;
           // T2+=q->cltime;
            freemem+=q->freem;
            taple+=q->taples;
            check();     //调用check()显示正在运行的,就绪的以及后备的作业信息
            free(q);    //释放作业
			getch();
            apply();    //分配作业
            getch();
        }
        else
        {
			if(start!=NULL)
			{
			for(s=start;s->next!=NULL;)
			 {s=s->next;}
             s->next=q;
			 s=q;
			}
			else
			{
				start=q;
				printf("\n用户名--作业名--状态--到达时间-需运时-已运时-需占内存-需taple 数量 \n");
			    disp(s);
				if(ready==NULL)
					printf("\nEnd of some work!Good luck!\n");
			}
			if(start==NULL&&ready!=NULL)
				apply();
        }
		
    }
}
            

                
void main()       //主程序
{
  printf("\n\n\t\t---------I hope to get a high mark!:)-----------\t\t\n");
  printf("\n\t\t.多道批处理作业FCFS调度演示.\n");
  inital();
  apply();
  running();
}

