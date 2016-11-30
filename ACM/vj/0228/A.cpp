#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);

}

int cal(int a,int b)
{
    int flag = 180*3600;
    int maxx = max(a,b);
    int minn = min(a,b);
    int rest = maxx - minn;
    if(rest >flag)
    {
        rest = 360 * 3600 - rest;
    }
    int g = gcd(rest, 3600);
    int d = 3600 / g;
    if(d != 1)
        printf("%d/%d ",rest/g,d);
    else
        printf("%d ",rest/g);
}

int main()
{
    int t;
    int h,m,s;
    int hh,mm,ss;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d:%d:%d",&h,&m,&s);
        ss = s*60*360;
        mm = (m*60 +s)*360;
        hh = (h%12 * 30) *3600 +(m*60 +s)*30;
        cal(hh,mm);
        cal(hh,ss);
        cal(mm,ss);
        printf("\n");
    }
return 0;
}
