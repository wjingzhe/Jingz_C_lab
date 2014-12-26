#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int year;
    int month;
    int day;
}DATE;

int days(DATE d1,int flag)
{
    int day = 0;
    switch(d1.month)
    {
        case 12:day = day+30;
        case 11:day = day+31;
        case 10:day = day+30;
        case 9: day = day+31;
        case 8: day = day+31;
        case 7: day = day+30;
        case 6: day = day+31;
        case 5: day = day+30;
        case 4: day = day+31;
        case 3: day = day+28+flag;
        case 2: day = day+31;
        case 1: day = day+d1.day;
        default:return day;
    }
}//days


int main()
{
    int day = 0;
    int flag = 0;
    DATE d1;
    printf("please input year,month,day\n");
    scanf("%d,%d,%d",&d1.year,&d1.month,&d1.day);
    if((d1.year%4==0&&d1.year%100!=0)||d1.year%400==0)//ÈòÄê
        flag = 1;
    while(d1.month==2&&d1.day>28&&(d1.day!=29||flag==0))
    {
        printf("Please input the right day:\n");
        scanf("%d",&d1.day);
    }
    day = days(d1,flag);

    printf("%d/%d/%d is the %dth day in the year\n",d1.year,d1.month,d1.day,day);
    return 0;
}
