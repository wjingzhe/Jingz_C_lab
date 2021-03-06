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
void BubbleSort(T a[],int i,int j)//升序排列
{
	for(;i<j;i++)
	{
		for(int k =0;k<j-i;k++)
		{
			if(a[k]>a[k+1]) Swap(a,k,k+1);
		}
	}
}

void main()
{
	char c;
	do
	{
		int n;
		cout<<"Numbers to sort(long int):n=";
		cin>>n;
		long *a = new long[n];
		cout<<"Input "<<n<<" number:"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<"a["<<i<<"]=";
			cin>>a[i];
		}
		BubbleSort(a,0,n-1);
		for(int j=0;j<n;j++)
		{
			cout<<a[j]<<" ";
		}
		char c;
		cout<<endl<<"Do you want to exit?(y/n)";
		cin>>c;
	}while(c!='y');
}