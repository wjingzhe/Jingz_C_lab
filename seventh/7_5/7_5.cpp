#include<stdio.h>
void main()
{
	int row=0,colum=0,i,j,max;
	int a[3][4]={{1,2,3,4},{9,8,7,6},{-10,10,-5,2}};
	max=a[0][0];
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
			if(a[i][j]>max)
			{
				max=a[i][j];
				row=i;colum=j;
			}
	}
	printf("max=%d,row=%d,colum=%d\n",max,row,colum);
}