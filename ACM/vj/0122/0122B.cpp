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
}

int main()
{
    int z,h;
    long long a,b,m,ans;
    scanf("%d",&z);
    while(z--)
    {
        ans = 0;
        scanf("%lld",&m);
        scanf("%d",&h);
        while(h--)
        {
            scanf("%lld %lld",&a,&b);
            ans += mod(a,b,m);
            ans %= m;
        }
        printf("%lld\n",ans);
    }

return 0;
}
