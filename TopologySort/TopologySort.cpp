#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

template<class T>
void TopologySort(T a[],int m,int n)
{
	ofstream os("graph.txt");
	int* flag = new int[n-m];
	int CountFlag = 0;
	for(int k = 0;k<n;k++,CountFlag++)
	{
		flag[k] = 1;
	}
	do
	{
		for(int j = m;j<n;j++)
		{
			int column = 0;
			for(int i = m;i<n;i++)
			{
				column+=(a[i*n+j]-48);
			}
			if(column==0 && flag[j])
			{
				for(int k=0;k<n;k++)
				{
					a[j*n+k] = 48;
				}

				flag[j] = 0;
				CountFlag--;
				cout<<"Node:"<<j<<"--"; 
				os<<j+48;
				os<<"--";
			}
		}
	}while(CountFlag);
	string s = "end";
	os<<s;
	os.close();
	cout<<"end"<<endl;
}

void main()
{
	int n=0;
	cout<<"Make sure your file named \"matrix.txt\" had stored the adjacency matrix and then enter the dimension:";
	cin>>n;
	char* a = new char[n*n];
	ifstream fin("matrix.txt");
	char c;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n+1;j++)
		{
			fin.read(reinterpret_cast<char *>(&c),sizeof(char));
			if(j<7) 
			{
				a[i*n+j] = c;
				cout<<a[i*n+j]<<" ";
			}
		}
		cout<<endl;
	}
	fin.close();
	TopologySort(a,0,n);

}