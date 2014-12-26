#include<stdio.h>
void main()
{
	int grade,point;
	scanf("%d",&point);
	grade = point/10;
	switch(grade)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5: grade = 'E';break;
	case 6: grade = 'D';break;
	case 7: grade = 'C';break;
	case 8: grade = 'B';break;
	case 9: 
	case 10:grade = 'A';break;
	}
	printf("%c\n",grade);
}