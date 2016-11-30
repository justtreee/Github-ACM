#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

double f(double x)
{
    return 8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*x+6;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double x,y,l=0,r=100,mid;
        scanf("%lf",&y);
        if(y<f(0) || y>f(100))
        {
            printf("No solution!\n");
            continue;
        }
        else
        {
            while(r-l > 1e-6)
            {
                mid = l + (r-l)/2;
                if(f(mid) > y)
                    r = mid;
                else
                    l = mid;
            }
            printf("%.4lf\n",r);
        }
    }


return 0;
}
