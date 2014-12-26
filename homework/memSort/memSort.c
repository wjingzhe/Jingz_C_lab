#include "stdio.h"
#include "conio.h"

#define getpch(type,size) (type*)malloc(sizeof(type)*size)
#define MINSIZE sizeof(FQ)*2

int memsize;/*模拟的内存大小*/
char *memfirst; /*模拟的内存所占的首地址*/
int frees=-1;/*free指向模拟内存的空闲分区的首地址*/



struct fq/*分区链的结构*/
{
    int link;  /*指向前一个空闲分区块或者后一个空闲分区块*/
    int size;  /*空闲分区的大小*/
}*p=NULL;

typedef struct fq FQ;

int insert(int first,int fqsize)/*构造空闲分区时插入空闲分区*/
{
    int tmp,tmp1,a;
    if(frees<0)/*空闲分区为空*/
    {
        frees=first;
        p=(FQ*)(memfirst+first);/*在空闲分区的首部来记录该空闲分区的信息和前向指针*/
        p->link=-1; /*因为是第一个,前向指针为-1*/
        p->size=fqsize;
        /*printf("%d",(char*)p-memfirst); */
        p=(FQ*)(memfirst+first+fqsize-sizeof(FQ)); /*在空闲分区的尾部来记录该空闲分区的信息和前向指针*/
        p->size=fqsize;
        p->link=-1; /*因为是第1个,所以后向指针也为-1*/
        return 1;
    }
    else
    {
        if(first<frees) /*要插入的空闲分区首地址小于所空闲分区的首地址*/
        {
            if(first+fqsize>frees)/*判断是否有重叠部分*/
            {
                printf("空闲分区有部分重叠!");
                return -1;
            }
            if(first+fqsize==frees)/*要插入的空闲分区刚好可以和最前面的分区合并,就和最前面的分区合并*/
            {
                p=(FQ*)(memfirst+frees);
                p=(FQ*)(memfirst+frees+p->size)-1;
                p->size=p->size+fqsize;
                tmp=p->size;
                p=(FQ*)(memfirst+first);
                p->size=tmp;
                p->link=-1;
                frees=first;
                return 1;
            }
            p=(FQ*)(memfirst+first);/*如果不能合并就把这个空闲分区插入到最前面*/
            p->size=fqsize;
            p->link=-1;
            p=(FQ*)(memfirst+first+fqsize)-1;
            p->size=fqsize;
            p->link=frees;
            p=(FQ*)(memfirst+frees);
            p->link=first+fqsize-sizeof(FQ);
            frees=first;
            return 1;
        }
        else/*空闲分区不是应该插入到最前面*/
        {
            tmp=frees;
            p=(FQ*)(memfirst+frees);
            p=(FQ*)(memfirst+frees+p->size)-1;
            tmp1=p->link;
            while(first>tmp1&&tmp1!=-1)/*找到应该插入的位置*/
            {
                p=(FQ*)(memfirst+tmp1);
                p=(FQ*)((char*)p+p->size)-1;
                tmp=tmp1 ;
                tmp1=p->link;
            }
            if(tmp1==-1)/*要插入的空闲分区大于所有空闲分区*/
            {
                p->link=first;
                tmp=(char*)p-memfirst;
                p=(FQ*)(memfirst+first);
                p->size=fqsize;
                p->link=tmp;
                p=(FQ*)(memfirst+first+p->size)-1;
                p->size=fqsize;
                p->link=-1;
                return 1;
            }
            else
            {
                if(first+fqsize==tmp1)
                {
                    p=(FQ*)(memfirst+tmp1);
                    a=p->link;/*保存前一空闲分区的尾部*/
                    p=(FQ*)(memfirst+tmp1+p->size)-1;
                    p->size=p->size+fqsize;
                    fqsize=p->size;/*保存当前的大小*/
                    p=(FQ*)(memfirst+first);
                    p->size=fqsize;
                    p->link=a;
                    p=(FQ*)(memfirst+a);
                    p->link=first;
                    return 1;
                }
                p->link=first;
                tmp=(char*)p-memfirst;
                p=(FQ*)(memfirst+first);
                p->size=fqsize;
                p->link=tmp;
                p=(FQ*)(memfirst+first+p->size)-1;
                p->size=fqsize;
                p->link=tmp1;
                tmp=(char*)p-memfirst;
                p=(FQ*)(memfirst+tmp1);
                p->link=tmp;
                return 1;

            }

        }
    }
    return -1;
}

make()/*初始化空闲分区链*/
{
    int first,fqsize;
    char yn;
    printf("请输入内存的空间大小（字节为单位）：");
    scanf("%d",&memsize);
    memfirst=getpch(char,memsize);
    printf("======下面开始构造空闲分区========\n");
    while(1)
    {
        printf("请输入空闲分区的首地址：");
        scanf("%d",&first);
        if(first<0)/*判断首地址是否合法*/
        {
            printf("首地址不能小于0!请重新输入!\n");
            continue ;
        }
        printf("请输入空闲分区的大小：");
        scanf("%d",&fqsize);
        if(fqsize<MINSIZE)
        {
            printf("空闲分区大小不能小于%d!请重新输入!\n",MINSIZE);
            continue ;
        }
        insert(first,fqsize);/*调用insert函数的空闲分区插入*/
        getchar();
        printf("是否继续构造空闲分区表(Y/N)?");
        scanf("%c",&yn);
        if(yn!='y'&&yn!='Y') break;
    }
}       


display()/*显示目前的空闲分区状态*/
{
    int next;
    FQ * hou;
    printf("======当前空闲分区的状态========\n首地址  \t大小\n");
    if(frees==-1) return ;
    p=(FQ*)(memfirst+frees);
    hou=(FQ*)((char*)p+p->size)-1;
    next=hou->link ;
    while(next!=-1)
    {
        printf("%d\t\t%d\n",(char*)p-memfirst,p->size);
        p=(FQ*)(memfirst+hou->link);
        hou=(FQ*)((char*)p+p->size)-1;
        next=hou->link;
    }
    printf("%d\t\t%d\n",(char*)p-memfirst,p->size);

}


int freemem()/*回收内存*/
{
    char yn;
    int first,size,res;
    FQ *tmp1,tmp2;
    printf("请输入要回收的内存的首址:");
    scanf("%d",&first);
    printf("请输入要回收的内存的大小:");
    scanf("%d",&size);
    res=insert(first,size);
    if(res==1)
    {
        printf("首址为:%d,大小为:%d有内存已成功回收!\n",first,size);
        return 1;
    }
    return -1;
}


int requestmen()/*分配内存*/
{
    int size;
    FQ *tmp,*tmp1;
    printf("请输入要分配的内存大小:");
    scanf("%d",&size);
    if(size<0||size>memsize)
    {
        printf("要分配的内存大小太大或太小!\n");
        return ;
    }
    p=(FQ*)(memfirst+frees);
    tmp=p;
    p=(FQ*)((char*)p+p->size)-1;
    if(p->size>=size)
    {
        if(p->size-size>=2*sizeof(FQ))/*如果剩余空间大于2倍的FQ的大小,就把前面部分分配出去*/
        {
            p->size=p->size-size;
            size=p->size;/*保存新的空闲分区大小*/
            tmp1=(FQ*)((char*)(++p)-size);
            tmp1->size=size;
            tmp1->link=-1;
            frees=(char*)tmp1-memfirst;
            return (char*)tmp-memfirst;
        }
        else/*如果剩余空间小于2倍的FQ的大小,就把整个空闲分区分配出去*/
        {
            frees=p->link;
            return (char*)tmp-memfirst;
        }
    }
    while(p->size<size&&p->link!=-1)
    {
        p=(FQ*)(memfirst+p->link);
        tmp=p;
        p=(FQ*)((char*)p+p->size)-1;
    }
    if(p->size>=size)
    {
       if(p->size-size>=2*sizeof(FQ))
       {
            p->size=p->size-size;
            size=p->size;/*保存新的空闲分区大小*/
            tmp1=(FQ*)((char*)(++p)-size);
            tmp1->size=size;
            tmp1->link=tmp->link;
            p=(FQ*)(memfirst+tmp->link);
            p->link=(char*)tmp1-memfirst;
            return  (char*)tmp-memfirst;
       }
       else
       {
            tmp1=(FQ*)(memfirst+tmp->link);
            tmp1->link=p->link;
            tmp1=(FQ*)(memfirst+p->link);
            tmp1->link=tmp->link;
            return  (char*)tmp-memfirst;
       }
    }
    else
    {
        if(p->link==-1)
        {
            printf("没有足够大的内存可分配!\n");
            return -1;
        }
    }
    return -1;
}

main()
{
    char yn;
    int res;
    make();
    display();
    while(1)
    {
        getchar();
        printf("是否分配内存(Y/N)?");
        scanf("%c",&yn);
        if(yn=='y'||yn=='Y')
        {
            res=requestmen();
            if(res==-1) printf("分配失败!\n");
            else
            {
                printf("分配成功!分配的首址为:%d\n",res);
                display();
            }

        }
        else
        {
            getchar();
            printf("是否回收内存(Y/N)?");
            scanf("%c",&yn);
            if(yn=='y'||yn=='Y')
            {
                freemem();
                display();
            }
            else
            {
                getchar();
                printf("是否退出(Y/N)?");
                scanf("%c",&yn);
                if(yn=='y'||yn=='Y') break;
            }
        }
    }
}
