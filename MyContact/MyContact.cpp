#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 /****************************************************
  copyright：Personal Telphone
  Filename：  MyContact.cpp
  Version: C++6.0
  Date: 2012.12.19
  Description: 基于二叉排序树的个人通讯录
  Function List:
               initdata()  初始化内置数据
               insert()    添加联系人
               find()      查找联系人
               change()    修改联系人信息
               del()       删除联系人
               destory()   释放空间
 *******************************************************/

 int current = 0;          //标记通讯录人数
 int flag;                        //查找结果标记

 typedef struct student
 {
     char name[20];
     char number[11];
     char bir[10];
     char tel[15];
 }student;                   //定义二叉链表结构体

 student myClass[50];

 typedef struct tree
 {
     struct student *people;
     struct tree *left;
     struct tree *right;
 }tree;                       //定义树

 tree *root = NULL;       //根节点初始化为空

 void initdata()                      //内置的联系人的初始化
 {
     strcpy( myClass[current].name,"路人甲");
     strcpy( myClass[current].bir,"19900101");
     strcpy( myClass[current].tel,"11111111111");
     strcpy( myClass[current].number,"311100001");
     current++;
     strcpy( myClass[current].name,"演员乙");
     strcpy( myClass[current].bir,"19900202");
     strcpy( myClass[current].tel,"22222222222");
     strcpy( myClass[current].number,"311100002");
     current++;
     strcpy( myClass[current].name,"导演丙");
     strcpy( myClass[current].bir,"19900303");
     strcpy( myClass[current].tel,"3333333333");
     strcpy( myClass[current].number,"311100003");
     current++;
     strcpy( myClass[current].name,"我是丁");
     strcpy( myClass[current].bir,"19900404");
     strcpy( myClass[current].tel,"88888888888");
     strcpy( myClass[current].number,"311100008");
     root = (tree *)malloc(sizeof(tree));
     root->people = &myClass[0];
     root->left = NULL;
     root->right = NULL;
 }


 void insert(tree * root,student *q)              //排序二叉树按学号递归插入
 {
     flag = 0;
    if(strcmp(root->people->number,q->number) == 0)
     {
         printf("插入不成功,相同学号的人已存在\n");
		 flag = 1;
         return;
     }//if

    else if(strcmp(root->people->number,q->number) > 0 )
    {
         if(root->left == NULL)
		{
         tree *p = (tree *)malloc(sizeof(tree));
         p->people = q;
         p->left = NULL;
         p->right = NULL;
         root->left = p;
		}
		else
		 {
			insert(root->left,q);
		 }
    }//if
    else
     {
        if( root->right == NULL)
		 {
			 tree *p = (tree *)malloc(sizeof(tree));
			 p->people= q;
			 p->left = NULL;
			 p->right = NULL;
			 root->right = p;
		 }
		else
		{
			insert(root->right,q);
		}
	}//if_else_if
}//insert

 int find(tree *root,char *p)                    //先根遍历查找
  {
      int flag;
      if( root!= NULL )
      {
         if( strcmp(root->people->name,p) == 0)
		 {
			 printf("已找到该联系人:\n");
             printf("姓名:%s      学号:%s      生日:%s      电话:%s\n",root->people->name,root->people->number,root->people->bir,root->people->tel);
             return 1;                                  //查找成功标记
		 }
		flag = find(root->left,p);
		if(flag>0)
		{
          return 1;
		}
		flag = find(root->right,p);
	    if(flag > 0)
		{
			  return 1;
		}
     }
      return 0;
 }//find

 int change(tree *root,char *p)          //先根遍历，查找到后修改
 {
    int flag;
    if(root != NULL)
     {
        if( strcmp(root->people->name,p) == 0)
		{
          int accept = 0;
          char buff[20];
          while(1)
		  {
              if(accept == 5)
               {
				  system("cls");
				  break;
			  }
			  printf("姓名:%s      学号:%s      生日:%s      电话:%s\n",root->people->name,root->people->number,root->people->bir,root->people->tel);
			  printf("请输入要修改的选项:\n");
			  printf("1 修改姓名\n");
			  printf("2 修改学号\n");
			  printf("3 修改生日\n");
			  printf("4 修改电话\n");
			  printf("5 退出\n");
			  printf("请输入:");
			  scanf("%d",&accept);
			 switch(accept)
			  {
              case 1:
              {
                   system("cls");
                   printf("你想把名字修改为:");
                   scanf("%s",buff);
                   strcpy(root->people->name,buff);
                   printf("修改成功\n");
                   break;
                }
              case 2:
              {
                    system("cls");
                    printf("你想把学号修改为(9位31110开头):");
                    scanf("%s",buff);
                    strcpy(root->people->number,buff);
                    printf("修改成功\n");
                    break;
               }
              case 3:
               {

                    system("cls");
                    printf("你想生日把修改为:");
                   scanf("%s",buff);
                    strcpy(root->people->bir,buff);
                    printf("修改成功\n");
                    break;
               }
               case 4:
               {
                    system("cls");
                    printf("你想把电话修改为(11位):");
                    scanf("%s",buff);
                    strcpy(root->people->tel,buff);
                    printf("修改成功\n");
                    break;
               }
               case 5:
               {
                    break;
               }
               default:
               {
                    printf("输入有误，请重新输入\n");
                    break;
               }

			}//switch

		 }//while
          return 1;
    }//if

     flag = change(root->left,p);
     if(flag >0 )
     {
        return 1;
     }
    flag = change(root->right,p);
     if(flag >0)
     {
         return 1;
     }
   }//if
     return 0;
}//change

 void print(tree *root)
 {
     if(root != NULL)
    {
        printf("\n姓名:%s      学号:%s      生日:%s      电话:%s",root->people->name,root->people->number,root->people->bir,root->people->tel);
        print(root->left);
		putchar('\n');
        print(root->right);
     }
 }

 tree * findparent(char *p,tree *root,tree *parent)               //找寻待删除结点的父母结点
  {
    if( root != NULL)
     {
         if( strcmp(root->people->name,p) == 0 )
    {
         return parent;                                 //和返回结点所在层次类似
     }
         parent = findparent(p,root->left,root);
     if(parent != NULL)
     {
         return parent;
     }
    parent = findparent(p,root->right,root);
     if(parent != NULL)
     {
        return parent;
     }
     }
     return NULL;
 }

 void my_remove(tree *parent,tree *child)                 //删除结点
 {
     if(child->left == NULL && child->right == NULL)       //叶子节点
     {
         tree *temp = child;
     if(temp == root)                        //删除的是根
     {
        root = NULL;
         free(temp);
         return;
     }
     if(parent->left == child)                 //判断是父母的左孩子还是右孩子
    {
         parent->left = NULL;
     }
     else
     {
         parent->right = NULL;
     }
        free(temp);
     }
     else
    {
         if( child->left != NULL && child->right == NULL)          //1度结点
     {
         if(parent == NULL)                             //删除的是根结点
         {
             root = root->left;
               free(child);
         return;
         }
        if( parent->left == child)                    //判断左右孩子，由其父母收养
         {
            parent->left = child->left;
         }
         else
         {
             parent->right = child->left;
         }
         free(child);
     }
     else
     if( child->left == NULL && child->right != NULL)
     {
         if(parent == NULL)
         {
             root = root->right;
                 free(child);
         return;
         }
         if( parent->left == child)
        {
             parent->left = child->right;
         }
        else
         {
             parent->right = child->right;
         }
        free(child);
     }
     else                                               //二度结点
     {
         tree *temp,*temppar;
         temp = child->right;
         temppar = child;
         while(temp->left != NULL)                //找其中根遍历下的后继结点
         {
             temppar = temp;
             temp = temp->left;
        }
         strcpy(child->people->name,temp->people->name);
         strcpy(child->people->bir,temp->people->bir);
         strcpy(child->people->tel,temp->people->tel);
         strcpy(child->people->number,temp->people->number);
         if( temppar == child)                              //后继结点为待删除结点右孩子
         {                                                  //注意这种情况
             temppar->right = temp->right;
         }
         else
         {
             temppar->left = temp->right;
        }
         free(temp);
     }
     }
 }

 void del(char *q)
 {
     tree *parent;
     parent = findparent(q,root,NULL);
     if( parent == NULL && ( strcmp( root->people->name,q) != 0 ))
     {
         printf("通讯录中没有此联系人,删除失败\n");
    return;
     }
     if( parent == NULL)                                //删除分两步，先找到其父母结点，再
     {                                                  //分情况删除
         my_remove(parent,root);
    }
      else
     {
         if(  parent->left != NULL && (strcmp(parent->left->people->name,q) == 0 ) )
     {
        my_remove(parent,parent->left);
     }
     else
     {
         my_remove(parent,parent->right);
     }
     }
 }

void destory(tree *root)
{
    if(root != NULL)                    //释放空间
    {
        destory(root->left);
        destory(root->right);
        free(root);
     }
 }

 void disp()
 {
     int fun;
     char accept[20];
     while(1)
     {
		  fun = 5;
		  printf("现有联系人如下：\n");//按先序遍历
		  print(root);
		  printf("         请输入要选择的功能\n");
		  printf("/************************************/\n");
		  printf("         1.添加联系人\n");
		  printf("         2.修改联系人信息\n");
		  printf("         3.查找联系人\n");
		  printf("         4.删除联系人\n");
		  printf("         5.退出\n");
		  printf("/************************************/\n");
		  printf("请输入:");
		  scanf("%d",&fun);
		  if(fun=='1'||fun=='2'||fun=='3'||fun=='4'||fun=='5')
		  {
			  switch(fun)
			  {
				 case 1:
				{
					 system("cls");
					  if(root == NULL)
					   {
						  current++;
						  root = (tree *)malloc(sizeof(tree));
						  printf("请输入要添加的联系人姓名\n");
						  scanf("%s",accept);
						  strcpy(myClass[current].name,accept);

						  printf("请输入要添加联系人学号(9位:31110开头)\n");
						  scanf("%s",accept);
						  strcpy(myClass[current].number,accept);

						  printf("请输入要添加的联系人生日\n");
						  scanf("%s",accept);
						  strcpy(myClass[current].bir,accept);

						  printf("请输入要添加的联系人电话(11位)\n");
						  scanf("%s",accept);
						  strcpy(myClass[current].tel,accept);

						 root->people = &myClass[current];
						 root->left = NULL;
						 root->right = NULL;
						 printf("添加完成\n");
						 break;
					 }//if
					  current++;
					  printf("请输入要添加的联系人姓名\n");
					  scanf("%s",accept);
					  strcpy(myClass[current].name,accept);

					  printf("请输入要添加的联系人学号(9位:31110开头)\n");
					  scanf("%s",accept);
					  strcpy(myClass[current].number,accept);

					  printf("请输入要添加的联系人生日\n");
					  scanf("%s",accept);
					  strcpy(myClass[current].bir,accept);

					  printf("请输入要添加的联系人电话(11位)\n");
					  scanf("%s",accept);
					  strcpy(myClass[current].tel,accept);

					  insert(root,&myClass[current]);

					  if(flag == 1)
					  {
						  break;
					  }
					  printf("添加完成\n");
					  break;
				}//case1

				case 2:
				  {
				   system("cls");
				   if(root == NULL)
				   {
					   printf("通讯录为空\n");
					   break;
				   }
				   printf("请输入要修改的联系人姓名:\n");
				   scanf("%s",accept);
				   fun = change(root,accept);
				   if(fun == 0)
				   {
					   printf("没有你要联系人\n");
				   }
				   break;
				}//case2

				case 3:
				 {
				   system("cls");
				   if(root == NULL)
				   {
					   printf("通讯录为空\n");
				   break;
						  }
				   printf("请输入要查找的联系人姓名:\n");
				   scanf("%s",accept);
				  fun = find(root,accept);
				   if(fun == 0)
				   {
					  printf("联系人未找到\n");
				   }
				   break;
				}//case3

				case 4:
				{
				  system("cls");
				 if( root == NULL)
				  {
					 printf("通讯录为空\n");
					 break;
					}
				   printf("请输入要删除的联系人姓名:");
				   scanf("%s",accept);
				   del(accept);
				   break;
				 }//case4

				 case 5:
				 {
				   system("cls");
				   printf("正在清除数据\n");
				   destory(root);
				   printf("多谢使用本通讯录!\n");
				   exit(0);
				 }//case5

				 default:
				 {
				   system("cls");
				   printf("输入有误，请重新输入!\n");
				   break;
				 }//default

			}//switch
		}//if
		else continue;
     }//while
 }//disp

  int main()
  {
     int i;
     printf("正在初始化系统\n");
     initdata();
     for(i = 1;i <= current;i++)
     {
         insert(root,&myClass[i]);
     }
     disp();
     return 0;
 }
