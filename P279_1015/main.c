#include <stdio.h>
#include <stdlib.h>

int main()
{
    void avsco(float *pscore,float *paver);
    //count the average of every student's scores

    void avcour1(float *pscore,char (*pcourse)[10]);
    //count the average of course one' scores

    void fail2(float *pscore,int *pnum,float *paver,char (*pcourse)[10]);
    //find out students who failed on two courses

    void good(float *pscore,int *pnum,float *paver,char (*pcourse)[10]);
    //find out students who do better in exam


    int i,j,*pnum,num[4];
    pnum = num;
    float score[4][5],*pscore;
    //create the score array and apointer,which point to the array
    pscore = &score[0][0];
    float  aver[4],*paver;
    //create the array of the aver of score  and apointer,which point to the array
    paver = aver;
    char course[5][10],(*pcourse)[10];
    pcourse = course;

    printf("input course:\n");

    for(i = 0;i<5;i++)
    {
        scanf("%s",course[i]);
    }
    printf("\n");

    printf("Please inout NO. and scores:\n");
    printf("NO.");
    for(i = 0;i<5;i++)
    {
        printf(",%s",course[i]);
    }
    printf("\n");

    for(i = 0;i<4;i++)
    {
        scanf("%d",&num[i]);
        for(j = 0;j<5;j++)
        {
            scanf("%f",pscore+5*i+j);
        }
    }

    printf("\n\n");

    avsco(pscore,paver);
    //count the average of every student's scores
    avcour1(pscore,pcourse);
    //count the average of course one' scores
    printf("\n\n");
    fail2(pscore,pnum,paver,pcourse);
    //find out students who failed on two courses
    printf("\n\n");
    good(pscore,pnum,paver,pcourse);
    //find out students who do better in exam
    return 0;
}

void avsco(float *pscore,float *paver)
{
    int i,j;
    float sum,average;
    for(i = 0;i<4;i++)
    {
        sum = 0.0;
        for(j = 0;j<5;j++)
        {
            sum += *(pscore+5*i+j);
        }
        average = sum/5;
        *(paver+i) = average;
    }//for
}//avsco

void avcour1(float *pscore,char (*pcourse)[10])
{//count the average of course one' scores
    int i;
    float sum,average;
    for(i = 0;i<4;i++)
        sum += *(pscore+5*i);
    average = sum/4;
    printf("course1:%s,average score:%7.2f\n",*pcourse,average);
}

void fail2(float *pscore,int *pnum,float *paver,char (*pcourse)[10])
{//find out students who failed on two courses
    int i,j,k,label;
    printf("      =======Student who is failed======  \n");
    printf("NO.");
    for(i = 0;i<5;i++)
        printf("%11s",*(pcourse+i));
    printf("   average\n");
    for(i = 0;i<4;i++)
    {
        label = 0;
        for(j = 0;j<5;j++)
        {
            if(*(pscore+5*i+j)<60.0) label++;
        }//for
        if(label>=2)
        {
            printf("%d",*(pnum+i));
            for(k = 0;k<5;k++)
                printf("%11.2f",*(pscore+5*i+k));
            printf("%11.2f\n",*(paver+i));
        }//if
    }//for
}//fail2

void good(float *pscore,int *pnum,float *paver,char (*pcourse)[10])
{//find out students who do better in exam
    int i,j,k,n;
    printf("      =======Student whose score is good======  \n");
    printf("NO.");
    for(i = 0;i<5;i++)
        printf("%11s",*(pcourse+i));
    printf("   average\n");
    for(i = 0;i<4;i++)
    {
        n = 0;
        for(j = 0;j<5;j++)
            if(*(pscore+5*i+j)>85.0) n++;
        if((n==5)||(*(paver+i)>90.0))
        {
            printf("%d",*(pnum+i));
            for(k = 0;k<5;k++)
                printf("%11.2f",*(pscore+5*i+k));
            printf("%11.2f\n",*(paver+i));
        }//if
    }//for
}//good
