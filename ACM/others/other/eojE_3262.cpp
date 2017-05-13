#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    LL x,n;
    while(~scanf("%lld%lld",&x,&n))
    {
        for(LL i=2; i<=n; i++)
        {
            LL res = lcm(x,i);
            cout<<res/x<<endl;
        }
    }

    return 0;
}
