#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 100005
long long l[M],r[M],init[M],maxx;
int n,t;
int main()
{
    while(~scanf("%d",&n) && n)
    {
        maxx = -1;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&init[i]);
        }
        l[1] = 1;
        r[n] = n;
        for(int i=2; i<=n; i++)
        {
            t = i;
            while(t>1 && init[i]<=init[t-1])//while is wrong..why?
            {//init[i-1] -> init[t-1]
                t = l[t-1];
            }
            l[i] = t;
        }

        for(int i=n-1; i>=1; i--)
        {
            t = i;
            while(t<n && init[i]<= init[t+1])
            {
                t = r[t+1];
            }
            r[i] = t;
        }
        //long long showl,showr;
        for(int i=1; i<=n; i++)
        {
            if((r[i] - l[i] + 1)*init[i] > maxx)
            {
                //showl = l[i];
                //showr = r[i];
                maxx = (r[i] - l[i] + 1)*init[i];

            }
        }
        //printf("%lld  %lld\n",showl,showr);
        printf("%lld\n",maxx);
    }
return 0;
}



