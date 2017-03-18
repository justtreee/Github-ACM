#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
typedef long long LL;
int main()
{
    LL a,b,n;
    while(~scanf("%lld%lld%lld",&a,&b,&n))
    {
        LL x,t,tt=INF,ansx=1e7;
        for(x=1; x<=n; x++)
        {
            if(n%x) continue;
            t=1LL*n/x*(a+1LL*b*x*x);
            if(tt>t)
            {
                tt = t;
                ansx = x;
            }
        }
        cout<<ansx<<endl;
    }

    return 0;
}
