#include<iostream>
#include<windows.h>
#include<malloc.h>
#include"AVLTree.h" 
using namespace std;


#define INCREASEMENT 5;
void main()
{
	int i = 0;//第几棵树
	int k = 0;//循环控制量
	int num = 0;//输入数据总数
	float *temp;//float型数组输入暂存
	float *BSTData;//float型数组存储从平衡二叉树中读取的系列
	float key;//float型单个数据暂存
	BSTree p;
	bool runCreate = true;
	bool runSearch = true;
	bool runInsert = true;
	bool runDelete = true;
	bool runMerge = true;
	bool runDisp = true;
	bool taller = false;
	bool lower = false;

	int treeMAX = 5;//深林中树的总数，初始值为5
	bool *treeFlag = (bool *)malloc(sizeof(bool)*treeMAX);
	int treeCount = 0;
	BSTree *T = (BSTree *)malloc(sizeof(BSTree)*treeMAX);
	for(k = 0;k<treeMAX;k++)
	{
		T[k] = NULL;
		treeFlag[k] = false;
	}
	k = 0;
	
	char ch,c;//ch作为跳转控制量,c为查看树时候的屏幕控制量；
	bool runMain = true;
	cout<<"---------------数据结构：平衡二叉树的演示---------------"<<endl;
	cout<<"********************************************************"<<endl;
	cout<<"*****           Press enter to continue         *****"<<endl;
	cout<<"********************************************************"<<endl;
	getchar();
	cout<<"Loading..."<<endl;
	Sleep(1000);
	CreateAVL(T[0]);       //默认构造一棵空树
	treeFlag[0] = true;
	treeCount++;

	for(;ch!=12&&ch!=27&&runMain;)
	{
		system("cls");
		cout<<"---------------数据结构：平衡二叉树的演示---------------"<<endl;
		cout<<"********************************************************"<<endl;
		cout<<endl<<"\t\t0、初始化"<<endl;
		cout<<"\t\t1、查找遍历"<<endl;
		cout<<"\t\t2、插入"<<endl;
		cout<<"\t\t3、删除"<<endl;
		cout<<"\t\t4、合并拆分"<<endl;
		cout<<"\t\t5、显示树"<<endl;
		cout<<"\t\t6、退出"<<endl;
		cout<<endl<<"********************************************************"<<endl;
		cout<<"请输入要选择的操作：";
		cin>>ch;           //输入选择

		if('0'<=ch&&ch<='6')//处理正确操作
		{
			switch(ch)
			{
			case '0'://初始化
				runCreate = true;
				for(;runCreate;)
				{//for
					system("cls");
					cout<<"---------------    平衡二叉树：初始化    ---------------"<<endl;
					cout<<"********************************************************"<<endl;
					cout<<endl;
					cout<<"\t\t1、默认初始化（置空树）"<<endl;
					cout<<"\t\t2、新建空树"<<endl;
					cout<<"\t\t3、在位构建含有n个随机元素的平衡二叉树（不覆盖非空平衡二叉树）"<<endl;
					cout<<"\t\t4、输入n个元素并新建成平衡二叉树"<<endl;
					cout<<"\t\t5、选择要操作的树"<<endl;
					cout<<"\t\t6、返回"<<endl;
					cout<<endl;
					cout<<"********************************************************"<<endl;
					cout<<"请输入要选择的操作：";
					cin>>ch;           //输入选择

					if('1'<=ch&&ch<='6')//处理正确操作
					{
						switch(ch)
						{
						case '1'://默认初始化（置空树）
							if(IsAVL(T[i])&&treeFlag[i])//置空
							{
								ClearTree(T[i]);
							}
							else 
							{
								treeFlag[i] = true;
								treeCount++;
								ClearTree(T[i]);
							}
							cout<<"树T["<<i<<"]初始化成功"<<endl;
							break;
						case '2'://新建空树
							for(i = 0;treeFlag[i]&&i<treeMAX;i++);//找到空位置
							if(i>=treeMAX)//内存已满，再次申请内存
							{
								treeMAX+=INCREASEMENT;
								T = (BSTree *)realloc(T,treeMAX);
								treeFlag = (bool *)realloc(treeFlag,treeMAX);
								for(k = i;k<treeMAX;k++)
								{
									T[k] = NULL;
									treeFlag[k] = false;
								}
								k = 0;
							}
							if(CreateAVL(T[i]))
							{
								treeCount++;
								treeFlag[i] = true;
								cout<<"平衡二叉树T["<<i<<"]"<<"初始化成功"<<endl;//默认成功
							}
							else
							{
								cout<<"平衡二叉树T["<<i<<"]"<<"初始化失败"<<endl;//当T[i]已是树的时候提示是否清空重建，此功能在实用版本中实现
								i--;
							}
							Sleep(2000);
							break;

						case '3'://若该树不是平衡二叉树且不是控二叉树，原地建含有n个随机元素的平衡二叉树
							if(!treeFlag[i]||IsAVL(T[i])||IsEmptyTree(T[i]))//如果不是平衡二叉树，则初始化当前树为空树，否则过到空位置建树
							{
								ClearTree(T[i]);
							}
							else //下个位置建树
							{
								for(i = 0;treeFlag[i]&&i<treeMAX;i++);//找到空位置
								if(i>=treeMAX)//内存已满，再次申请内存
								{
									treeMAX+=INCREASEMENT;
									T = (BSTree *)realloc(T,treeMAX);
									treeFlag = (bool*)realloc(treeFlag,treeMAX);
									for(k = i;k<treeMAX;k++)
									{
										T[k] = NULL;
										treeFlag[k] = false;
									}//for
									k = 0;
								}//if
							}//if_else

							cout<<"请问要构建含有多少个元素的二叉树(n):";
							cin>>num;
							if(CreateAVL(T[i],num))
							{
								treeFlag[i] = true;
								cout<<"平衡二叉树T["<<i<<"]"<<"初始化成功"<<endl;//默认成功
							}
							else
							{
								cout<<"平衡二叉树T["<<i<<"]"<<"初始化失败"<<endl;//当T[i]已是树的时候提示是否清空重建，此功能在实用版本中实现
							}//if_else
							num = 0;//重置
							Sleep(2000);
							break;

						case '4'://输入n个元素并新建成平衡二叉树
							for(i = 0;treeFlag[i]&&i<treeMAX;i++);//找到空位置
							if(i>=treeMAX)//内存已满，再次申请内存
							{
								treeMAX+=INCREASEMENT;
								T = (BSTree *)realloc(T,treeMAX);
								treeFlag = (bool*)realloc(treeFlag,treeMAX);
								for(k = i;k<treeMAX;k++)
								{
									T[k] = NULL;
									treeFlag[k] = false;
								}
								k = 0;
							}//if
							cout<<"请问要构建含有多少个元素的二叉树(n):";
							cin>>num;
							temp = (float*)malloc(sizeof(float)*num);
							for(k = 0;k<num;k++)
							{
								cout<<"请输入第"<<k<<"个元素:";
								cin>>temp[k];
							}//for
							if(CreateAVL(T[i],temp,num))
							{
								treeCount++;
								treeFlag[i] = true;
								cout<<"平衡二叉树T["<<i<<"]"<<"初始化成功"<<endl;//默认成功
							}
							else
							{
								treeCount++;
								treeFlag[i] = true;
								cout<<"平衡二叉树T["<<i<<"]"<<"输入存在相同元素"<<endl;//当T[i]已是树的时候提示是否清空重建，此功能在实用版本中实现
							}
							free(temp);//重置
							k = 0;
							num = 0;
							Sleep(4000);
							break;

						case '5'://选择要操作的树
							cout<<"内存中树总共有"<<treeCount<<"棵，详情如下："<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"下标为"<<k<<"的树："<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}
							cout<<"请选择:";
							cin>>i;
							if(!IsAVL(T[i])||!treeFlag[i])
							{
								cout<<"T["<<i<<"]不是一棵平衡二叉树，请记得先初始化"<<endl;
							}
							else
								cout<<"选择成功，当前操作树为T["<<i<<"]"<<endl;
							k = 0;
							Sleep(2000);
							break;
								
						default: //退出
							runCreate = false;
						}//switch_初始化
					}//if
					else //处理正确操作
					{
						cout<<"请选择正确的操作！！"<<endl;
						Sleep(2000);
					}//if_else

				}//for_runCreate
				break;//switch_ch_runMain

			case '1':            //查找遍历
				if(!IsAVL(T[i])||!treeFlag[i]) 
				{
					cout<<"T["<<i<<"]不是一棵平衡二叉树，请先初始化"<<endl;
					Sleep(2000);
					runSearch = false;
					break;
				}
				else
					runSearch = true;

				for(;runSearch;)
				{
					system("cls");
					cout<<"---------------    平衡二叉树：查找遍历  ---------------"<<endl;
					cout<<"********************************************************"<<endl;
					cout<<endl;
					cout<<"\t\t1、查找"<<endl;
					cout<<"\t\t2、先序遍历"<<endl;
					cout<<"\t\t3、中序遍历"<<endl;
					cout<<"\t\t4、后序遍历"<<endl;
					cout<<"\t\t5、返回"<<endl;
					cout<<endl;
					cout<<"********************************************************"<<endl;
					cout<<"请输入要选择的操作：";
					cin>>ch;           //输入选择

					if('1'<=ch&&ch<='5')//处理正确操作
					{
						switch(ch)
						{
						case '1'://查找
							cout<<"请输入要查找的元素:";
							cin>>key;
							if(SearchAVL(T[i],key,T[i],p))
							{
								cout<<"元素"<<p->data<<"的地址是："<<p<<endl;
							}
							else 
							{
								if(p->data>key)
									cout<<"元素"<<key<<"应该插入为"<<p->data<<"的右孩子"<<endl;
								else 
									cout<<"元素"<<key<<"应该插入为"<<p->data<<"的左孩子"<<endl;
							}
							key = NULL;
							cout<<"Enter a key to continue:";
							cin>>c;;
							break;

						case '2'://先序遍历
							cout<<"树T["<<i<<"]如下："<<endl;
							TraverseAVL(T[i]);//树状显示
							num = 0;
							BSTData = PreOrderTraverseAVL(T[i],num);
							cout<<"先序遍历结果："<<endl;
							for(k = 0;k<num-1;k++)
							{
								cout<<BSTData[k]<<"-";
							}
							cout<<BSTData[num-1]<<endl;
							//重置
							k = 0;
							num =0;
							free(BSTData);
							BSTData = NULL;
							cout<<"Enter a key to continue:";
							cin>>c;
							break;

						case '3'://中序遍历
							cout<<"树T["<<i<<"]如下："<<endl;
							TraverseAVL(T[i]);//树状显示：
							num = 0;
							BSTData = InOrderTraverseAVL(T[i],num);
							cout<<"中序遍历结果："<<endl;
							for(k = 0;k<num-1;k++)
							{
								cout<<BSTData[k]<<"-";
							}
							cout<<BSTData[num-1]<<endl;
							k = 0;//重置
							num = 0;
							free(BSTData);
							BSTData = NULL;
							cout<<"Enter a key to continue:";
							cin>>c;
							break;

						case '4'://后序遍历
							cout<<"树T["<<i<<"]如下："<<endl;
							TraverseAVL(T[i]);//树状显示：
							num = 0;
							BSTData = PostOrderTraverseAVL(T[i],num);
							cout<<"后序遍历结果："<<endl;
							for(k = 0;k<num-1;k++)
							{
								cout<<BSTData[k]<<"-";
							}
							cout<<BSTData[num-1]<<endl;
							k = 0;//重置
							num = 0;
							free(BSTData);
							BSTData = NULL;
							cout<<"Enter a key to continue:";
							cin>>c;
							break;

						default: //退出
							runSearch = false;
						}//switch_Search
					}//if
					else //处理正确操作
					{
						cout<<"请选择正确的操作！！"<<endl;
						Sleep(2000);
					}//if_else

				}//for_runSearch

				break;//switch_ch_runMain

			case '2'://插入
				if(!IsAVL(T[i])||!treeFlag[i])
				{
					cout<<"T["<<i<<"]不是一棵平衡二叉树，请先初始化"<<endl;
					Sleep(2000);
					runInsert = false;
					break;
				}
				else
					runInsert = true;
				for(;runInsert;)
				{
					system("cls");
					cout<<"---------------    平衡二叉树：插入      ---------------"<<endl;
					cout<<"********************************************************"<<endl;
					cout<<endl;
					cout<<"\t\t1、插入单个元素"<<endl;
					cout<<"\t\t2、插入多个元素(录入)"<<endl;
					cout<<"\t\t3、插入多个元素(随机)"<<endl;
					cout<<"\t\t4、返回"<<endl;
					cout<<endl;
					cout<<"********************************************************"<<endl;
					cout<<"请输入要选择的操作：";
					cin>>ch;           //输入选择

					if('1'<=ch&&ch<='4')//处理正确操作
					{
						switch(ch)
						{
						case '1'://插入单个元素
							taller = false;
							cout<<"请输入要插入的元素:";
							cin>>key;
							if(InsertAVL(T[i],key,taller))
								cout<<"插入成功"<<endl;
							else
								cout<<"已存在相同元素"<<endl;
							key = NULL;//重置
							taller = false;
							Sleep(2000);
							break;

						case '2'://插入多个元素（录入）
							cout<<"请输入要插入的元素个数:";
							cin>>num;
							temp = (float*)malloc(sizeof(float)*num);
							for(k = 0;k<num;k++)
							{
								taller = false;
								cout<<"请输入第"<<k<<"个元素:";
								cin>>temp[k];
								if(InsertAVL(T[i],temp[k],taller))
									cout<<"元素"<<temp[k]<<"插入成功"<<endl;
								else
									cout<<"已存在相同元素"<<temp[k]<<endl;
							}
						    //重置
							k = 0;
							num = 0;
							taller = false;
							free(temp);
							temp = NULL;
							Sleep(2000);
							break;

						case '3'://插入多个元素（随机）
							cout<<"请输入要插入的元素个数:";
							cin>>num;
							temp = (float*)malloc(sizeof(float)*num);
							for(k = 0;k<num;k++)
							{
								taller = false;
								temp[k] = rand()%100;
								if(InsertAVL(T[i],temp[k],taller))
									cout<<"元素:"<<temp[k]<<"插入成功"<<endl;
								else
									cout<<"已存在相同元素:"<<temp[k]<<endl;
							}
							k = 0;
							num = 0;//重置
							taller = false;
							free(temp);
							temp = NULL;
							Sleep(2000);
							break;

						default: //退出
							runInsert = false;
						}//switch_Insert
					}//if
					else //处理正确操作
					{
						cout<<"请选择正确的操作！！"<<endl;
						Sleep(2000);
					}//if_else

				}//for_runInsert

				break;//switch_ch_runMain

			case '3'://删除
				runDelete = true;
				for(;runDelete;)
				{
					system("cls");
					cout<<"---------------    平衡二叉树：删除      ---------------"<<endl;
					cout<<"********************************************************"<<endl;
					cout<<endl;
					cout<<"\t\t1、删除单个元素"<<endl;
					cout<<"\t\t2、删除多个元素"<<endl;
					cout<<"\t\t3、清空树"<<endl;
					cout<<"\t\t4、销毁树"<<endl;
					cout<<"\t\t5、返回"<<endl;
					cout<<endl;
					cout<<"********************************************************"<<endl;
					cout<<"请输入要选择的操作：";
					cin>>ch;           //输入选择

					if('1'<=ch&&ch<='5')//处理正确操作
					{
						switch(ch)
						{
						case '1'://删除单个元素
							if(!IsAVL(T[i])||!treeFlag[i]) 
							{
								cout<<"T["<<i<<"]不是一棵平衡二叉树，请先初始化"<<endl;
								Sleep(2000);
								runDelete = false;
								break;
							}
							cout<<"目前树T["<<i<<"]如下："<<endl;
							TraverseAVL(T[i]);//树状显示：
							lower = false;
							cout<<"请输入要删除的元素:";
							cin>>key;
							if(DeleteAVL(T[i],key,lower))
								cout<<"删除成功"<<endl;
							else
								cout<<"不存在相同的元素"<<key<<endl;
							key = NULL;//重置
							lower = false;
							Sleep(2000);
							break;

						case '2'://删除多个元素
							if(!IsAVL(T[i])||!treeFlag[i]) 
							{
								cout<<"T["<<i<<"]不是一棵平衡二叉树，请先初始化"<<endl;
								Sleep(2000);
								runDelete = false;
								break;
							}
							cout<<"目前树T["<<i<<"]如下："<<endl;
							TraverseAVL(T[i]);//树状显示：
							lower = false;
							cout<<"请输入要删除的元素个数:";
							cin>>num;
							temp = (float*)malloc(sizeof(float)*num);
							for(k = 0;k<num;k++)
							{
								cout<<"请输入第"<<k<<"个元素";
								cin>>temp[k];
								if(DeleteAVL(T[i],temp[k],taller))
									cout<<"元素"<<temp[k]<<"删除成功"<<endl;
								else
									cout<<"不存在相同元素"<<temp[k]<<endl;
							}
							lower = false;//重置
							num = 0;
							k = 0;
							free(temp);
							temp = NULL;
							Sleep(2000);
							break;

						case '3'://清空树
							cout<<"内存中树如下："<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"下标为"<<k<<"的树："<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}
							cout<<"请输入要清空的树的下标（从0开始）:";
							cin>>k;
							for(;!IsAVL(T[k])||!treeFlag[k];)
							{
								cout<<"T["<<k<<"]不是一棵平衡二叉树，请重新输入下标（从0开始）:";
								cin>>k;
							}
							ClearTree(T[k]);//清空树
							k = 0;
							cout<<"清空成功"<<endl;
							Sleep(2000);
							break;

						case '4'://销毁树
							cout<<"内存中树如下："<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"下标为"<<k<<"的树："<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}
							cout<<"请输入要销毁的树的下标（从0开始）:";
							cin>>k;
							for(;!IsAVL(T[k])||!treeFlag[k];)
							{
								cout<<"T["<<k<<"]不是一棵平衡二叉树，请重新输入下标（从0开始）:";
								cin>>k;
							}
							ClearTree(T[k]);//清空树
							treeFlag[k] = false;
							treeCount--;
							k = 0;
							cout<<"销毁成功"<<endl;
							Sleep(2000);
							break;

						default: //退出
							runDelete = false;
						}//switch_Delete
					}//if
					else //处理正确操作
					{
						cout<<"请选择正确的操作！！"<<endl;
						Sleep(2000);
					}//if_else

				}//for_runDelete

				break;//switch_ch_runMain

			case '4'://合并拆分
				runMerge = true;
				for(;runMerge;)
				{
					system("cls");
					cout<<"---------------    平衡二叉树：合并拆分    ---------------"<<endl;
					cout<<"********************************************************"<<endl;
					cout<<endl;
					cout<<"\t\t1、合并新树"<<endl;
					cout<<"\t\t2、合并内存中的特定的两棵树"<<endl;
					cout<<"\t\t3、拆分树"<<endl;
					cout<<"\t\t4、返回"<<endl;
					cout<<endl;
					cout<<"********************************************************"<<endl;
					cout<<"请输入要选择的操作：";
					cin>>ch;           //输入选择

					if('1'<=ch&&ch<='4')//处理正确操作
					{
						switch(ch)
						{
						case '1'://合并新树 
							//显示内存中所有的树
							cout<<"内存中树如下："<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"下标为"<<k<<"的树："<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}
							if(!treeFlag[i]||!IsAVL(T[i]))//如果不是平衡二叉树，则初始化当前树为空树，否则寻找空位置建树
							{
								ClearTree(T[i]);
							}
							else //下个位置建树
							{
								for(i = 0;treeFlag[i]&&i<treeMAX;i++);//找到空位置
								if(i>=treeMAX)//内存已满，再次申请内存
								{
									treeMAX+=INCREASEMENT;
									T = (BSTree *)realloc(T,treeMAX);
									treeFlag = (bool*)realloc(treeFlag,treeMAX);
									for(k = i;k<treeMAX;k++)
									{
										T[k] = NULL;
										treeFlag[k] = false;
									}
									k = 0;
								}
							}//if_else
							cout<<"请输入新树的元素个数:";
							cin>>num;
							temp = (float*)malloc(sizeof(float)*num);
							for(k = 0;k<num;k++)
							{
								taller = false;
								cout<<"请输入第"<<k<<"个元素:";
								cin>>temp[k];
								if(InsertAVL(T[i],temp[k],taller))
									cout<<"元素"<<temp[k]<<"插入成功"<<endl;
								else
									cout<<"已存在相同元素"<<temp[k]<<endl;
							}
							cout<<"新树构建成功"<<endl;
							cout<<"请输入新树要并入树的下标（从0开始）:";
							cin>>k;
							for(;!IsAVL(T[k])||!treeFlag[k];)
							{
								cout<<"T["<<k<<"]不是一棵平衡二叉树，请输入主树的下标（从0开始）:";
								cin>>k;
							}
							MergeAVL(T[k],T[i]);//合并树
							//重置
							ClearTree(T[i]);
							k = 0;
							num = 0;
							free(temp);
							temp = NULL;
							cout<<"合并成功"<<endl;
							Sleep(2000);
							break;

						case '2'://合并内存中的特定的两棵树
							//显示内存中所有的树
							cout<<"内存中树如下："<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"下标为"<<k<<"的树："<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}

							cout<<"请输入主树的下标（从0开始）:";
							cin>>k;
							for(;!IsAVL(T[k])||!treeFlag[k];)
							{
								cout<<"T["<<i<<"]不是一棵平衡二叉树，请输入主树的下标（从0开始）:";
								cin>>k;
							}

							cout<<"请输入从树的下标（从0开始）:";
							cin>>num;
							for(;!IsAVL(T[num])||!treeFlag[num];)
							{
								cout<<"T["<<num<<"]不是一棵平衡二叉树，请输入从树的下标（从0开始）:";
								cin>>num;
							}
							MergeAVL(T[k],T[num]);//合并树
							treeFlag[num] = false;
							treeCount--;
							k = 0;//重置
							num = 0;
							cout<<"合并成功"<<endl;
							Sleep(2000);
							break;

						case '3'://拆分树
							//显示内存中所有的树
							cout<<"内存中树如下："<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"下标为"<<k<<"的树："<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}
							if(!treeFlag[i]||!IsAVL(T[i]))//如果不是平衡二叉树，则初始化当前树为空树，否则跳过空位置建树
							{
								ClearTree(T[i]);
							}
							else //下个位置建树
							{
								for(i = 0;treeFlag[i]&&i<treeMAX;i++);//找到空位置
								if(i>=treeMAX)//内存已满，再次申请内存
								{
									treeMAX+=INCREASEMENT;
									T = (BSTree *)realloc(T,treeMAX);
									treeFlag = (bool*)realloc(treeFlag,treeMAX);
									for(k = i;k<treeMAX;k++)
									{
										T[k] = NULL;
										treeFlag[k] = false;
									}
									k = 0;
								}
							}//if_else
							cout<<"请输入要拆分的树的下标（从0开始）:";
							cin>>k;
							for(;!IsAVL(T[k])||!treeFlag[k];)
							{
								cout<<"T["<<k<<"]不是一棵平衡二叉树，请输入树的下标（从0开始）:";
								cin>>k;
							}		
							if(!IsEmptyTree(T[k]))//分拆树,原树的右子树挂接为根，原根数据插入到左子树中，返回为左子树根。	
							{
								DistributeAVL(T[k],T[i]);
								treeFlag[i] = true;
								treeCount++;
								cout<<"拆分成功"<<endl;
							}
							else
							{
								cout<<"拆分失败：不能拆分空树"<<endl;
							}
							k = 0;
							Sleep(2000);
							break;


						default: //退出
							runMerge = false;
						}//switch_Merge
					}//if
					else //处理正确操作
					{
						cout<<"请选择正确的操作！！"<<endl;
						Sleep(2000);
					}//if_else

				}//for_runMerge

				break;//switch_ch_runMain

			case '5'://显示树	
				runDisp = true;
				for(;runDisp;)
				{
					system("cls");
					cout<<"---------------    平衡二叉树：显示      ---------------"<<endl;
					cout<<"********************************************************"<<endl;
					cout<<endl;
					cout<<"\t\t1、显示单树"<<endl;
					cout<<"\t\t2、显示所有树"<<endl;
					cout<<"\t\t3、返回"<<endl;
					cout<<endl;
					cout<<"********************************************************"<<endl;
					cout<<"请输入要选择的操作：";
					cin>>ch;           //输入选择

					if('0'<=ch&&ch<='3')//处理正确操作
					{
						switch(ch)
						{
						case '1'://显示单树			
							cout<<"请选择要显示树的下标(";
							for(k = 0;!treeFlag[k];k++) ;
							cout<<k;
							for(k++;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<","<<k;
							}
							cout<<"):";

							cout<<"请输入要显示的树的下标（从0开始）:";
							cin>>k;
							for(;!IsAVL(T[k])||!treeFlag[k];)
							{
								cout<<"T["<<k<<"]不是一棵平衡二叉树，请输入主树的下标（从0开始）:";
								cin>>k;
							}
							cout<<"第"<<k<<"棵树："<<endl;
							TraverseAVL(T[k]);
							cout<<endl;
							k = 0;
							num = 0;
							cout<<"Enter a key to continue:";
							cin>>c;
						//	getchar();
							break;

						case '2'://显示所有树
							//显示内存中所有的树
							cout<<"内存中树总共有"<<treeCount<<"棵，详情如下："<<endl;
							for(k = 0;k<treeMAX&&treeFlag[k];k++)
							{
								cout<<"下标为"<<k<<"的树："<<endl;
								TraverseAVL(T[k]);
								cout<<endl;
							}
							k = 0;
							cout<<"Enter a key to continue:";
							cin>>c;
						//	getchar();
							break;

						default: //退出
							runDisp = false;
						}//switch_Disp
					}//if
					else //处理正确操作
					{
						cout<<"请选择正确的操作！！"<<endl;
						Sleep(2000);
					}//if_else
				}//for_runDisp
				break;//switch_ch_runMain

			default://退出
				runMain = false;
			}//switch_ch_runMain

		}//if
		else //处理正确操作
		{
			cout<<"请选择正确的操作！！"<<endl;
			Sleep(2000);
		}//if_else

	}//for_runMain
}//main