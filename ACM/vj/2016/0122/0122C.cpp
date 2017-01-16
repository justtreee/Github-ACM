#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
double p,q,r,s,t,u;
double cal(double x);
int main()
{
    double low,high,temp;
    int flag = 1;
    while(~scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u))
    {
        low = 0;
        high = 1;
        flag = 1;
        while(high-low > 1e-9)
        {
            if((cal(low) > 0 && cal(high) > 0) || (cal(low) < 0 && cal(high) < 0))
            {
                printf("No solution\n");
                flag = 0;
                break;
            }
            temp = low + (high - low)/2.0;
            if(cal(temp) > 0)
                low = temp;
            if(cal(temp) < 0)
                high = temp;
        }
        if(flag)
            printf("%.4lf\n",high);
    }

return 0;
}

double cal(double x)
{
    return p*exp(-x) + q*sin(x) +r*cos(x) + s*tan(x) + t*x*x + u;
}
