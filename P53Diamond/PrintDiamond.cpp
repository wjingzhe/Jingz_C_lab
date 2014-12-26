#include<iostream>
using namespace std;

void main()
{
	int n;
	cout<<"A algorithm is a 1 * 1 box to start, always at the last graphics plus a circle around squares\nQ:How many squares to create In the n this time?"<<endl;
	cout<<"Enter a number:"<<endl;
	cin>>n;
	int i;
	for(i = 1;i<=n;i++)
	{
		int j;
		for(j = 1;j<=n-i;j++)
		{
			cout<<" ";
		}
    	for(j = 1;j<=2*i-1;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	for(i = n-1;i>=1;i--)
	{
		int j;
		for(j = 1;j<=n-i;j++)
		{
			cout<<" ";
		}
		for(j = 1;j<=2*i-1;j++)
		{
			cout<<"*";
		}
		cout<<endl;
		
	}

}