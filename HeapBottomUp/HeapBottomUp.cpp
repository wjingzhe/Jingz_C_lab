#include<iostream>
#include<time.h>
#include<cstdlib> 
#include<vector>
#include<math.h>
using namespace std;

void InitHeap(int a[],int n)//初始化，实现堆构造
{
	for(int i=n/2;i>=1;i--)
	{
		int k = i,j = 0;
		int v = a[k];
		bool heap = false;
		while(!heap&&2*k<=n)//实现父母优势
		{
			j = 2*k;
			if(j<n)//存在两个儿子
			{
				if(a[j]<a[j+1]) 
				{
					j = j+1;
				}
			}

			if(v>=a[j])
			{
				heap = true;
			}
			else 
			{
				a[k] = a[j];
				k = j;
			}
		}//while
		a[k] = v;
	}//for

}

void DispHeap(int a[],int m,int n)//阶梯式显示
{   
	int i = m,k = log(i)/log(2),j;
	if(i<n)
	{
		cout<<endl;
		for(j=0;j<k;j++)
		{
			cout<<" ";
		}
		cout<<a[i];
		DispHeap(a,2*i,n);
		if(2*i<n)
		{
			DispHeap(a,2*i+1,n);
		}
		return;
	}
}



int* InsertNode(int a[],int &n,int elem)//插入新结点，重新排序
{
	n++;
	int* b = new int[n]();
	b[0] = n;
	for(int count = 0;count<n-1;count++)
	{
		b[count] = a[count];
	}
	b[n-1] = elem;
	InitHeap(b,n);
	return b;
}

int SearchNode(int a[],int m,int n,int elem)//查找，最先查找的下标，不查找重复情况
{
	int index = -1;
	int i = m;
	if(i<n)
	{
		if(a[i] == elem) 
		{
			index = i;
			return index;
		}
		else if(a[i]<elem) 
		{
			return index;
		}
		else if(2*i<=n)
		{
			i = 2*i;
			index = SearchNode(a,i,n,elem);//查找左子树
			if(index==-1&&i<n)
			{
				i = i+1;
				index = SearchNode(a,i,n,elem);//查找右子树
			}
		}
	}
	return index;
}

void DestroyHeap(int a[],int n)//销毁堆
{
	for(int i = 1;i<n;)
	{	
		cout<<a[i]<<"--";
		a[i] = a[--n];
		InitHeap(a,n);
	}
}


void main()
{
	time_t timep; 
    struct tm *p;

	//时间函数
    char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};   			                  
    time(&timep); 
	p=gmtime(&timep);

	bool flag = true;//循环开关

	int n = 0;
	int* a;
	int* temp;
	cout<<"Press to enter..";
	
	do{	
		getchar();
		system("cls");
		char num;
		int elem,i,index;
		cout<<"\n-------------"<<endl;
		cout<<"1.初始化"<<endl;
		cout<<"2.插入结点"<<endl;
		cout<<"3.删除结点"<<endl;
		cout<<"4.查找结点"<<endl;
		cout<<"5.显示堆"<<endl;
		cout<<"6.销毁堆"<<endl;
		cout<<"0.退出"<<endl;
		cout<<"请输入数字选择对应操作：";
		cin>>num;
		switch (num){
		case '1'://初始化 
			system("cls");
			cout<<"请输入结点个数：";
			cin>>n;
			n++;
			a = new int[n]();//a[0]不存结点
			a[0] = n;
			cout<<"请输入相应结点（以空格分开）：";
			for(i = 1;i<n;i++)
			{
				cin>>a[i];
			}
			InitHeap(a,n-1);
		    DispHeap(a,1,n);
			break;

		case '2'://插入
			system("cls");
			int elem;
			cout<<"请输入要插入的结点（数字）：";
			cin>>elem;
			temp = a;
			a = InsertNode(a,n,elem); //在n个结点中插入新结点
			delete(temp);
			DispHeap(a,1,n);
			break;

		case '3'://删除 
			system("cls");
			cout<<"请输入要删除的结点（数字）：";
			cin>>elem;
			index = SearchNode(a,1,n,elem); 
			if(index!=-1)
			{
				for(i = index;i>1;)
				{
					i = i/2;
					a[index] = a[i];
					index = i;
				}
				n--;
				a[1] = a[n];
				InitHeap(a,n);
				cout<<endl<<elem<<"已被删除";
				
			}else
			{
				cout<<"不存在结点"<<elem;
			}
			DispHeap(a,1,n);
			break;

		case '4'://查找
			system("cls"); 
			cout<<"请输入要查找的结点（数字）：";
			cin>>elem;
			index = SearchNode(a,1,n,elem);
			if(index==-1)
			{
				cout<<"不存在结点"<<elem;
			}else
			{
				cout<<elem<<"的位置为:第"<<int(log(index)/log(2))+1<<"层,第"<<index-int(pow(2,log(index)/log(2)))+1<<"个";
			}
			DispHeap(a,1,n);
			break;

		case '5': 
			system("cls");
			DispHeap(a,1,n);
			break;

		case '6':
			system("cls");
			DestroyHeap(a,n);
			delete(a);
			break;

		case '0':
			flag = false;
			system("cls"); 
			break;
		}//switch

		getchar();
	}while(flag);

	cout<<1900+p->tm_year<<"年"<<1+p->tm_mon<<"月"<<p->tm_mday<<"日"; 
    cout << p->tm_hour << ":" <<p->tm_min << ":" <<p->tm_sec <<" " ;
}