#include <iostream>   
using namespace std;  
#define N 100   
int a[N][N];  
int b[N];  
  
void copy(int n)  
  
{     
    int m=n/2;    
    for(int i=0;i<m;i++)       
        for(int j=0;j<m;j++)           
        {             
            //由左上角小块的值算出对应的右上角小块的值             
            a[i][j+m]=a[i][j]+m;              
            //由右上角小块的值算出对应的左下角小块的值             
            a[i+m][j]=a[i][j+m];              
            //由左上角小块的值算出对应的右下角小块的值             
            a[i+m][j+m]=a[i][j];              
        }         
}  
void copyodd(int n)              // n/2为奇数时的合并算法   
{   int m=n/2;    
    for(int i=0;i<m;i++)       
    {         
        b[i]=m+i;         
        b[m+i]=b[i];          
    }     
    for(i=0;i<m;i++)       
    {         
        //由左上角小块的值算出相应的左下角小块的值         
        for(int j=0;j<m+1;j++)             
        {             
            if(a[i][j]>=m)                 
            {                 
                a[i][j]=b[i];                 
                a[m+i][j]=(b[i]+m)%n;                 
            }             
            else a[m+i][j]=a[i][j]+m;             
        }  
        //由左上角小块的值算出相应的右上角和右下角小块的值         
        for(j=1;j<m;j++)           
        {  
            a[i][m+j]=b[i+j];             
            a[b[i+j]][m+j]=i;             
        }         
    }     
}  
  
bool odd(int n)  
{  
    return n&1;  
}  
  
void makecopy(int n)  
{  
    if((n/2)>1&&odd(n/2))  
        copyodd(n);  
    else  
        copy(n);  
}  
  
void tourna(int n)  
{  
    if(n==1)  
    {  
        a[0][0]=0;  
        return;  
    }  
    if(odd(n))  
    {  
        tourna(n+1);  
        return;  
    }  
    tourna(n/2);  
    makecopy(n);  
}  
void main()  
{  
    int n,i,j; 
	printf("请输入要参加比赛的运动员人数:");
    scanf("%d",&n);
	printf("\n");
    tourna(n);  
    if(!odd(n))  
    {  
        for (i=0; i<n;i++)  
        {  
        if(i==0)  
            printf("运动员编号: ");   
        else  
            if(i<10)
			    printf("比赛第 %d天: ",i);
			else
				printf("比赛第%d天: ",i);
        for(j=0; j<n;j++)  
            printf("%d ",a[i][j]);
		printf("\n");            
        }  
    }  
    else  
    {  
        for (i=0; i<=n-1;i++)  
        {  
            if(i==0)  
                printf("运动员编号: ");  
            else  
                if(i<10)
			    printf("比赛第 %d天: ",i);
			else
				printf("比赛第%d天: ",i);  
            for(j=0; j<=n-1;j++)
				printf("%d ",a[i][j]);
			printf("\n");
        }  
    } getchar(); getchar();
}  