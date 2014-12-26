#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum color {red,yellow,blue,white,black};
    enum color i,j,k,pri;
    int n = 0,loop;
    for(i = red;i <= black;i++)
    {
        for(j = red;j <= black;j++)
        {
            if(i!=j)
            {
                for(k = red;k <= black;k++)
                {
                    if(i!=k&&j!=k)
                    {
                        n++;
                        printf("%-4d",n);
                        for(loop = 1;loop <= 3;loop++)
                        {
                            switch(loop)
                            {
                                case 1:
                                    pri = i;break;
                                case 2:
                                    pri = j;break;
                                case 3:
                                    pri = k;break;
                                default:
                                    break;
                            }//switch_loop

                            switch(pri)
                            {
                                case red: printf("%-10s","red");break;
                                case yellow: printf("%-10s","yellow");break;
                                case blue: printf("%-10s","blue");break;
                                case white: printf("%-10s","white");break;
                                case black: printf("%-10s","black");break;
                                default :break;
                            }//switch_pri
                        }//for_loop

                        printf("\n");
                    }//if
                }//for_k
            }//if
        }//for_j
    }//for_i

    printf("\ntotal:%5d\n",n);
    return 0;
}
