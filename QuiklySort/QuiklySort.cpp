#include<iomanip>
#include<iostream>
using namespace std;
template <class T>
void Swap(T a[],int i,int j)//交换两个数
{
	T temp = a[i];
	a[i] = a[j];
	a[j] = temp;

}

template <class T>
int Partition(T a[],int left,int right)//定位中轴，默认选择a[left]
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
		s = Partition(a,left,right);//选取中轴
		QuikSort(a,left,s-1); //排列前区间
		QuikSort(a,s+1,right);//排列后区间
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
		cout<<"Do you want to exit?(y/n)";
		char c;
		cin>>c;
	}
}