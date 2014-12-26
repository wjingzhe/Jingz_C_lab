#include<iostream>
using namespace std;

template <class T>
void Swap(T a[],int p,int q)//交换两个数
{
	T temp = a[p];
	a[p] = a[q];
	a[q] = temp;
}

template <class T>
void SelectSort(T a[],int i,int j)//升序排列
{
	for(;i<j;i++)
	{
		int min = i;
		for(int k = i+1;k<=j;k++)
		{
			if(a[k]<a[min]) min = k;
		}
		Swap(a,i,min);
	}
}

void main()
{
	for(char c=0;c!='y'&&c!='Y';)
	{
		int n;
		cout<<"Numbers to sort:n=";
		cin>>n;
		long *a = new long[n];
		cout<<"Input "<<n<<" number:"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<"a["<<i<<"]=";
			cin>>a[i];
		}
		SelectSort(a,0,n-1);
		for(int j=0;j<n;j++)
		{
			cout<<a[j]<<" ";
		}
		cout<<endl<<"Do you want to exit?(y/n)";
		char c;
		cin>>c;
	}
}