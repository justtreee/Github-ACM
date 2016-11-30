#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
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

struct node{
    int yy;
    int mm;
    int dd;

}a[400][12][3];
int main()
{
    for(int i=2000; i<=2399; i++)
    {
        for(int j=1; j<=12; j++)
        {
            for(int k=1; k<=21; k+=10)
            {

                if((tianshu(i,j,k)-3)%7==2)
                {
                    printf("%d %d %d\t\t",i,j,k);
                    a[i-2000][j-1][k/10].yy = i;
                    a[i-2000][j-1][k/10].mm = j;
                    a[i-2000][j-1][k/10].dd = k;
                }
            }
        }
    }

    int t,y,m,d,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&y,&m,&d,&n);
        int ty,pluss;
        ty = y;
        pluss =0;
        while(ty<2000)
        {
            ty+=400;
            pluss++;
        }
        while(ty>=2400)
        {
            ty-=400;
            pluss--;
        }
        printf("%d %d %d\n",a[ty-2000][m-1][d/10+n].yy+pluss*400,a[ty-2000][m-1][d/10+n].mm,a[ty-2000][m-1][d/10+n].dd);

    }

return 0;
}
