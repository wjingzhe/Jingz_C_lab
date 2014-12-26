#include <stdio.h>
#include <stdlib.h>

int main()
{
    char temp;
    int label = 0;
    int i = 0,j = 0,num = 0,a[10];
    printf("Please input a string:\n");
    temp = getchar();
    while(1)
    {
        if((temp>='0')&&(temp<='9'))
        {
            num = num*10+ temp-48;
            label = 1;
            temp = getchar();
        }
        else
        {
            if(label == 1)
            {
                a[i++] = num;
                num = 0;
                label = 0;
                j++;
            }
            if(temp=='\0'|| (temp >= 9&& temp<=13)) break;
            temp = getchar();
        }
    }//while
    for(i = 0;i<j;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}
