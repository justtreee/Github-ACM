#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M (1<<20)
#define INF (0x3f3f3f3f)
typedef long long ll;
int dp[42][M];
int a[40];

int main()
{
    int t,n,m,tt;
    scanf("%d",&t);
    for(tt=1; tt<=t; tt++)
    {
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);

        }
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<M; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i-1][j^a[i]];
            }
        }
        ll ans = 0;
        for(int i=m; i<M; i++)
        {
            ans += dp[n][i];
        }

        printf("Case #%d: %lld\n",tt,ans);
    }

return 0;
}
