#include<iostream>
using namespace std;

template <class T>
int BinarySearch(T a[],int left,int right,T toSearch)
{
	T l = left,
	  r = right;
	int m;
	while(l<=r)
	{
		m = (l+r)/2;
		if(a[m]==toSearch) return m;
		else if(a[m]<toSearch) l = m+1;
		else r = m-1;
	}
	return -1;
}


template <class T>
void Swap(T a[],int i,int j)
{
	T temp = a[i];
	a[i] = a[j];
	a[j] = temp;
//	cout<<a[i]<<" "<<a[j]<<" ";
}

template <class T>
int Partition(T a[],int left,int right)
{
	T p = a[left];
	int i = left,
		j = right+1;
	do
	{
		do{i++;}while(a[i]<p);
		do{j--;}while(a[j]>p);
		Swap(a,i,j);
	}while(i<j);
	Swap(a,i,j);
	Swap(a,left,j);
	return j;
}

template <class T>
void QuikSort(T a[],int left,int right)
{
	int s=0;
	if(left<right)
	{
		s = Partition(a,left,right);
		QuikSort(a,left,s-1); 
		QuikSort(a,s+1,right);
	}

	
}

void main()
{
	for(char c=0;c!='y'&&c!='Y';)//默认不退出
	{
		int n;
		cout<<"Numbers to sort:n=";//输入
		cin>>n;
		long *a = new long[n];
		cout<<"Input "<<n<<" number:"<<endl;;
		for(int i=0;i<n;i++)
		{
			cout<<"a["<<i<<"]=";
			cin>>a[i];
		}
		
		QuikSort(a,0,n-1);//快速排序

		for(int j=0;j<n;j++)
		{
			cout<<a[j]<<" ";//输出
		}
		long toSearch;
		cout<<endl<<"Please enter the number to find its index:";
		cin>>toSearch;
		int index = BinarySearch(a,0,n-1,toSearch);
		if(index!=-1){cout<<"The index is "<<index<<endl;}
		else cout<<"The number does not exist in the array."<<endl;
		cout<<"Do you want to exit?(y/n)";
		char c;
		cin>>c;
	}
}