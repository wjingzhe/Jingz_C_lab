#include<stdio.h>
#include<string.h>

void main()
{
	void sort(char(*p)[6]);
    int i;
	char str[10][6],(*p)[6];
	printf("intput 10 strings:\n");
	for(i=0;i<10;i++)
	{
		scanf("%s",str[i]);
	}
	p = str;
	sort(p);
	printf("Now, the sequence is:\n");
	for(i=0;i<10;i++)
		printf("%s\n",str[i]);

}

void sort(char(*str)[6])
{
	int i,j;
	char temp[6],*t=temp;
	for(i=0;i<9;i++)
		for(j=0;j<9-i;j++)
		{
			if(strcmp(str[j],str[j+1])>0)
			/* 以上3行的作用是将是s[j]指向的一维数组的内容与s[j+1]指向的一维数组的内容交换互换*/
			{
				strcpy(t,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],t);
			}
		}
}