#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 100005
long long s[M];
long long ans = 0;
int main()
{
    long long  n,q,t,p,x;
    scanf("%lld%lld",&n,&q);
    memset(s,0,sizeof(s));
    while(q--)
    {
        ans = 0;
        scanf("%lld%lld%lld",&t,&p,&x);
        if(t==1)
        {
            s[p] += x;
        }
        if(t==2) //l=p,r=x
        {
            for(int i=p; i<=x; i++)
            {
                if(s[i]>ans)
                    ans = s[i];
            }
            printf("%lld\n",ans);
        }

    }

return 0;
}

