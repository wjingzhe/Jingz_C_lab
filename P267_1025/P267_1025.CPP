#include<stdio.h>
void main()
{
	float score[][4] = {{60,70,80,90},{56,89,67,88},{34,78,90,66}};
	float *search(float(*pointer)[4]);
	float *p;
	int i;
	for(i = 0;i<3;i++)
	{
		p = search(score+i);
		if(p==*(score+i))
		{
			printf("No.%d scores:",i);
			int j;
			for(j = 0;j<4;j++)
			{
				printf("\t%5.2f",*(p+j));
			}printf("\n");
		}
	}
	
}

float *search(float(*pointer)[4])
{
	int i;
	float *p;
	p = *(pointer+1);//+1为了区别不及格是找到的pointer（指向一个4维数组）
	for(i = 0;i<4;i++)
	{
		if(*(*pointer+i)<60) p = *pointer;
	}
	return p;
}