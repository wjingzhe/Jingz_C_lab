#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
#define MAX 48;

template<class T>
T* WarShall(T a[],int m,int n,int l)
{
	if(--l)
	{
		T *b = WarShall(a,m,n,l);
		for(int k = 0;k<n;k++)
		{
			for(int i = 0;i<n;i++)
			{	
				for(int j = 0;j<n;j++)
				{
					a[i*n+j]=(b[i*n+k]+b[k*n+j]<=a[i*n+j])?b[i*n+k]+b[k*n+j]:a[i*n+j];			
				}//for j
			}//for i
		}//for k,±éÀú¾ØÕóÔªËØ
	}//if ×öµÝ¹é¿ØÖÆ

	return a;
}

void main()
{
	int n=0;
	cout<<"Make sure your file named \"FloydInput.txt\" had stored the adjacency matrix and then enter the dimension:";
	cin>>n;
	int* a = new int[n*n];
	ifstream fin("FloydInput.txt");
	char c;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n+1;j++)
		{
			fin.read(reinterpret_cast<char *>(&c),sizeof(char));
			if(j<n) 
			{
				if((int)c==48)
				{ 
					cout<<c<<" ";
				}else
				{
					cout<<c<<" ";
					c= c - 48;
				}
				a[i*n+j] =(int)c;
				
			}
		}
		cout<<endl;
	}
	cout<<"Its distance matrix is:"<<endl;
	fin.close();
	WarShall(a,0,n,n-1);
	ofstream os("graph.txt");
	for(i = 0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(i==j)
			{
				a[i*n+j] = 0;
			}
			os<<a[i*n+j]<<"  ";
			cout<<a[i*n+j]<<" ";
		}
		os<<'\n';
		cout<<endl;
	}
	os.close();
}