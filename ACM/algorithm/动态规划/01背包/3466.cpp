#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 5005
int n,m;
struct item{
    int p,q,v;
}t[M];
bool cmp(item a,item b)
{
    return a.q-a.p<b.q-b.p;
}
int dp[M];
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d",&t[i].p,&t[i].q,&t[i].v);
        }
        memset(dp,0,sizeof(dp));
        sort(t,t+n,cmp);
        for(int i=0; i<n; i++)
        {
            for(int j=m; j>=t[i].p; j--)
            {
                if(j>=t[i].q)
                {
                    dp[j] = max(dp[j-t[i].p]+t[i].v,dp[j]);
                }
            }
        }
        printf("%d\n",dp[m]);
    }


return 0;
}

