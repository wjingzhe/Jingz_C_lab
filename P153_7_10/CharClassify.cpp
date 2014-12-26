#include<stdio.h>
void main()
{
	char ch[3][9];
	int SLetter = 0,CLetter = 0,Num = 0,Space = 0,Other = 0;
	for(int i = 0;i<3;i++)
	{
		gets(ch[i]);
		ch[i][9] = '\0';
	}
	for(i = 0;i<3;i++)
	{
		for(int j = 0;j<8;j++)
		{
			if(ch[i][j]>=48 && ch[i][j]<58)
			{
				Num++;
			}
			else if(ch[i][j]>=65 && ch[i][j]<91)
			{
				CLetter++;
			}
			else if(ch[i][j]>=97 && ch[i][j]<123)
			{
				SLetter++;
			}else if(ch[i][j]==' ')
			{
				Space++;
			}else Other++;
		}
	}

	printf("\nSLetter = %d\nCLetter = %d\nNum = %d\nSpace = %d\nOther = %d\n",SLetter,CLetter,Num,Space,Other);
	
	for(i = 0;i<3;i++)
	{
		for(int j  = 0;j<8;j++)
			printf("%c",ch[i][j]);
		printf("\n");
	}

}