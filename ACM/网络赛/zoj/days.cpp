#include <iostream>
#include <cstdio>
using namespace std;
int s[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool leap(int year)

{

  if(year%4!=0 || year%100==0 && year%400!=0)

    return false;

  return true;

}



int days(int year,int month,int day)

{

  int sum=day;

  for(int i=1;i<month;i++)

    sum=sum+s[i];

  if(leap(year)) sum++;

  return sum;

}



int tianshu(int year,int month,int day)  ///计算2000-1-1至今的天数

{

  int y29=(year-2000)/4+1;

  int y28=(year-2000)-y29;

  int sum=0;

  sum=sum+y29*366+y28*365+days(year,month,day);

  return sum;



}

int main()
{
    printf("%d\n",tianshu(2000,3,1)-3);
    return 0;
}
