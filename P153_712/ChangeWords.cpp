#include<stdio.h>
void main()
{
	char ch[100];
	int i;

	gets(ch);

	printf("\n");

	for( i = 0;i<100;i++)
	{
		if(ch[i]>=65&&ch[i]<=90)
			ch[i] = 90-(ch[i]-65);

		if(ch[i]>=97&&ch[i]<=122)
			ch[i] = 122-(ch[i]-97);
	}
	printf("%s\n",ch);
}
