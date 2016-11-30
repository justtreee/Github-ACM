#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 10000
#define mod 9901
#define INF (0x3f3f3f3f)
typedef long long ll;

ll powermod(ll p,ll n)
{
    int r = 1;
    while(n)
    {
        if(n%2 != 0)
        {
            r = (r * p)%mod;
        }
        n/=2;
       p = p*p%mod;
    }
    return r;
}

ll sum(ll p,ll n)
{
    if(n == 0)
        return 1;
    if(n%2)
        return (sum(p,n/2)*(1+powermod(p,n/2+1)))%mod;
    else
        return (sum(p,n/2-1)*(1+powermod(p,n/2+1))+powermod(p,n/2))%mod;
}
int main()
{
    int a,b,p[M],n[M];
    while(~scanf("%d%d",&a,&b))
    {
        int i,k=0;
        for(int i=2; i*i<=a; )
        {
            if(a%i == 0)
            {
                p[k] = i;
                n[k] = 0;
                while(!(a%i))
                {
                    n[k]++;
                    a/=i;
                }
                k++;
            }
            if(i==2)
                i++;
            else
                i+=2;
        }

        if(a!=1)
        {
            p[k] = a;
            n[k++] = 1;

        }
        int ans = 1;
        for(int i=0; i<k; i++)
        {
            ans = (ans*(sum(p[i],n[i]*b)%mod))%mod;

        }
        printf("%d\n",ans);
    }
return 0;
}
