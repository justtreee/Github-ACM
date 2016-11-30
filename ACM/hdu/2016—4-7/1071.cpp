#include <iostream>
#include <cstdio>
using namespace std;
double a,b,c,k,d,ans;

double f(double x)
{
	return a * x * x * x / 3 - (2 * a * b + k) * x * x / 2 + (a * b * b + c - d) * x;
}

int main()
{
    int t;
    double x1,x2,x3,y1,y2,y3;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        b = x1;
        c = y1;
        a = (y2-y1)/(x2-x1)/(x2-x1);
        k = (y3-y2)/(x3-x2);
        d = y2 - k*x2;
        printf("%.2lf\n",f(x3)-f(x2));
    }
    return 0;
}
