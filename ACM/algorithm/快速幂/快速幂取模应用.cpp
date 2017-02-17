#include <stdio.h>
#include <algorithm>
using namespace std;

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



    /*while(b--)
    {
        r = (a * r)%p;

    }
    return r;*/
}

int main()
{
    int a,b,p;
    while(~scanf("%lld %lld %lld",&a,&b,&p))
    {
        printf("%lld\n",mod(a,b,p));
    }

return 0;
}
