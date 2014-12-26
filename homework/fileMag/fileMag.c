#include "stdio.h"
#define getpch(type,num) (type*)malloc(sizeof(type)*num)

struct ufd{ /* 用户文件目录 */
    char filename[10];/*文件名*/ 
    char procode[3];/*保护码*/
    int length;
    }*p;

typedef struct ufd UFD;

struct mdf{ /* 主目录MDF */
    char name[10]; 
    struct UFD* directory; /*下一个进程控制块的地址 */
    }maindir[10];

typedef struct mdf MDF;

int usernum;
int filenum[10];

main()
{
    int i,j,tmp;
    FILE *fp;
    printf("=====以下开始构造目录=====\n");
    printf("请输入要构造的用户数:");
    scanf("%d",&usernum);
    for(i=0;i<usernum;i++)
    {
        printf("请输入第%d要构造的用户名:",i+1);
        scanf("%s",maindir[i].name);
    }
    printf("用户名输入完毕!\n");
    for(i=0;i<usernum;i++)
    {
        printf("请输入第%d个用户名:%s要构造的文件数(小于10):",i+1,maindir[i].name);
        scanf("%d",&filenum[i]);
        p=getpch(UFD,10);
        maindir[i].directory=p;
        printf("==以下为第%d个用户的构造文件==\n",i+1);
        for(j=0;j<filenum[i];j++)
        {
            printf("请输入要构造的文件名:");
            scanf("%s",p[j].filename);
            printf("请输入要建立的文件的属性(输入3位的数字,对应:读,写,执行.):");
            scanf("%s",p[j].procode);
            printf("请输入要构造的文件的长度:");
            scanf("%d",&p[j].length);
        }
        printf("构造完成！");
    }

    fp=fopen("dat","wb");
    fwrite(&usernum,sizeof(int),1,fp);
    for(i=0;i<usernum;i++)
    {
        fwrite(maindir[i].name,sizeof(char)*10,1,fp);
    }
    for(i=0;i<usernum;i++)
    {
        fwrite(&filenum[i],sizeof(int),1,fp);
        p=maindir[i].directory;
        fwrite(p,sizeof(UFD),10,fp);
    }
    fclose(fp);
        printf("usernum:%d\n",usernum);
    for(i=0;i<usernum;i++)
    {
        printf("%s\n",maindir[i].name);
        p=maindir[i].directory;
        for(j=0;j<filenum[i];j++)
    	{
            printf("name:%s\n",p[j].filename);
            printf("code:%d\n",p[j].procode);
            printf("length:%d\n",p[j].length);
    	}
    }

}
