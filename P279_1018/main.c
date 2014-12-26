#include <stdio.h>
#include <stdlib.h>

void main()
{
char *month_name[13] = {"illegal name","January","Fe3bruary","March","April","May","June","July","Augest","September","Octber","Novemer","December"};
int n;
printf("input month:\n");
scanf("%d",&n);
if((n<=12)&&(n>=1))
printf("It's %s.\n",*(month_name+n));
else
printf("It is wrong.\n");
}
