#include<iomanip>
#include<iostream>
using namespace std;
//将from[0]至from[right-left+1]拷贝到d
template <class T>
void Copy(T d[],T from[],int left,int right)
{
	int size = right-left+1;
	for(int i = 0;i<size;)
	{
		d[left++] = from[i++];
	}
}

//合并有序数组a[left:i],a[i+1:right]到b，得到新的有序数组b
template <class T>
void Merge(T a[],T b[],int left,int m,int right)
{
	int a1bg = left,
		a1end = m,
		a2bg = m+1,
		a2end = right,
		bbg = 0;
	for(int j=0;j<right-left+1;j++)//执行right-left+1次循环
    {
    if(a1bg>a1end){b[bbg++]=a[a2bg++];continue;}//如果第一个数组结束，拷贝第二个数组的元素到b
    if(a2bg>a2end){b[bbg++]=a[a1bg++];continue;}//如果第二个数组结束，拷贝第一个数组的元素到b
    if(a[a1bg]<a[a2bg]){b[bbg++]=a[a1bg++];continue;}//如果两个数组都没结束，比较元素大小，把较小的放入b
    else{b[bbg++]=a[a2bg++];continue;}
    }
}

template <class T>
void MergeSort(T a[],int left,int right)
{
	T *b = new T[right-left+1];
	if(left<right)
	{
		int m = (left+right)/2;
		MergeSort(a,left,m);//分治
		MergeSort(a,m+1,right);
		Merge(a,b,left,m,right);//合并
		Copy(a,b,left,right);//复制回原数组
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
		MergeSort(a,0,n-1);
		for(int j=0;j<n;j++)
		{
			cout<<a[j]<<" ";
		}
		cout<<"Do you want to exit?(y/n)";
		char c;
		cin>>c;
	}
}