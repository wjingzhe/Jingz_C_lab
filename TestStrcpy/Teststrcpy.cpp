#include "iostream.h"
#include "stdio.h"
#include "string.h"

void main()
{
	void strcpy (char *sor,char *dri);
	char str[]="123313313";
	char *p = new char(strlen(str)+1);
	strcpy (str,p);
	

}

void strcpy (char *sor,char *dri)
{
	int i,j,n=0;
	for(i = 0; ; i++)
	{
		if(*(sor+i) != '\0')
		{
			n++;
		}
		else
			break;
	}
	for(j = 0;j<n;j++)
	{
		*(dri+j) = *(sor+j);
	}
	*(dri+j) = '\0';
	
	printf("%s",dri);
	
}