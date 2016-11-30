#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000000007

long long mod(long long a,long long b,long long p)
{
    long long r,t;
    r = 1;
    t = a;
    while(b)
    {
        if(b%2 != 0)
        {
            r = (r * t)%p;
        }
        b >>=1;
        t = (t*t)%p;
    }
    return r;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",mod(2,n-1,M)-1);

    }
return 0;
}
