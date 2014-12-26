#include <stdio.h>
#include <math.h>

/* 检验该年是否为闰年 */
int Leap(int year)
{
	if(((year%4==0)&&(year%100!=0))||(year%400==0))
		return 1;
	else
		return 0;
}

int Day(int y,int m,int d)//-1年份不合理，-2月份不合理，-3日期不合理
{
    int day_tab[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int k = Leap(y);
	if(y<=0||y>9999) return -1;//添加每年日期上限判定------------测试测试添加
	else if(m>12||m<=0) return -2;//添加每月日期上限判定------------测试测试添加
	else if(m==2&&d>day_tab[m-1]+k) return -3;
	else if((d>day_tab[m-1]&&m!=2)||d<=0) return -3;

	int i = 0,n=1; /* 计算该年份（如2010年）1月1日是星期几 */
	for(i=1;i<y;i++)
	{
		if(Leap(i))
			n = (n+366)%7;
		else
			n = (n+365)%7;
	}//for

	/* 计算该月份1日是星期几 */
	for(i=1;i<m;i++)
	{
		switch(i)
		{
		case 2:
			if(k)
			{
				n = (n+29)%7;
			}
			else
			{
				n = (n+28)%7;
			}
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			n = (n+30)%7;
			break;

		default:
            n = (n+31)%7;
		} //swtich(i)

	}//for
	/* 最后，计算这一天是星期几 */
	n = (n+d-1)%7;
	return n;
}//Day


int main()
{
	int year = 1,month = 1,day = 1;//无意思初始化
	int i=0,j = 0,k=1,t = 0;//k为用例数，t为年月日判定
	int count = 0;//计算位数使用
	char ch;
	char data[15];
//	char *p = data;
	FILE *fp;
	/*
	文件格式要求：
	1、行末结束符为回车符。
	2、最末行不用结束符，以默认结束符结束。
    3、数据类型为X/XX/XX（年/月/日）
	*/
	if((fp=fopen("test.txt","r"))==NULL)
	{
		printf("cannot open the file\n");
		return 0;
	}


loopwhile:while((ch=fgetc(fp))!=EOF)
	{
	//	fread(data,1,8,fp);
	//	ch=fgetc(fp);
		 year = 0;
		 month = 0;
		 day = 0;
		 i = 0;
		 j = 0;
		 t = 0;
		 count = 0;

//读取一项数据数据项:年份1-4位，月份、日份则为1-2位。
		for(i = 0;(ch!='\n')&&(ch!='\r')&&(ch!=EOF)&&i<15;i++)
		{
			if((ch<'0'||ch>'9')&&i<=14&&ch!='/')//出现非数字数据
			{
				while((ch!='\n')&&(ch!='\r')&&(ch!=EOF))
				{
					data[i] = ch;
					ch = fgetc(fp);
				}
				data[i] = '\0';
				printf("用例%d、出错：数据项(%s)含有非数字字符\n",k++,data);
				goto loopwhile;//跳到大循环继续下个数据
			}//if
			else if(ch=='/')//提取年月
			{
				switch(t)
				{
				case 0:
					while(j<i)
					{
						year = year*10+(data[j++]-48);
					}
					count = (j>4)?j:count;
					t++;
					data[i] = ch;
					ch = fgetc(fp);
					break;

				case 1:
					for(j = 1;data[i-j]!='/';j++)
					{
						month += (data[i-j]-48)*(int)pow(10,j-1);
					}
					count = (j>3)?j:count;
					t++;
					data[i] = ch;
					ch = fgetc(fp);
				}//switch(t)提取年月

			}//if_elseif_else
			else//其余情况直接存放
			{
				data[i] = ch;//正常读取数据
				ch=fgetc(fp);
				if(((ch =='\n')||(ch=='\r')||(ch==EOF)||(i==14))&&(t==2))//提取日份
				{
					for(j = 1,day = data[i]-48;data[i-j]!='/';j++)
					{
						day = day+(data[i-j]-48)*10;
					}
					count = (j>2)?j:count;
					t=0;
				}
			}


		}//for读取一项数据


			data[i] = '\0';//字符串数组结束符

			if(count>0)
				i = -4;
			else
				i = Day(year,month,day);//计算日期为一个星期第几天

			switch(i)
			{
			case 0:
				printf("用例%d、出错：%s是星期日\n",k++,data);
				break;

			case 1:
				printf("用例%d、出错：%s是星期一\n",k++,data);
				break;

			case 2:
				printf("用例%d、出错：%s是星期二\n",k++,data);
				break;

			case 3:
				printf("用例%d、出错：%s是星期三\n",k++,data);
				break;

			case 4:
				printf("用例%d、出错：%s是星期四\n",k++,data);
				break;

			case 5:
				printf("用例%d、出错：%s是星期五\n",k++,data);
				break;

			case 6:
				printf("用例%d、出错：%s是星期六\n",k++,data);
				break;

			case -1:
				printf("用例%d、出错：%s年份不在合理范围\n",k++,data);
				break;

			case -2:
				printf("用例%d、出错：%s月份不在合理范围\n",k++,data);
				break;

			case -3:
				printf("用例%d、出错：(%s)日份不在合理范围\n",k++,data);
				break;

			case -4:
				printf("用例%d、出错：(%s)年月日位数超出范围\n",k++,data);
			}//switch(i)
	}//while

	fclose(fp);
	return 0;
}
