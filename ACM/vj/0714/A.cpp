//unfinished

#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 102
#define INF (0x3f3f3f3f)
typedef long long ll;

int dp[105][55];
int main()
{
    int t,n,m,s[55][55],a[105];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&s[i][j]);
            }
        }
        for(int i=1 ;i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dp,-1,sizeof(dp));
        if((a[1]!=-1))
            dp[1][a[1]] = 0;
        else
        {
            for(int i=1; i<=m; i++)
            {
                dp[1][i] = 0;
            }
        }

        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(dp[i-1][j]!= -1)
                {
                    if(a[i]!=-1)
                    {
                        dp[i][a[i]] = max(dp[i][a[i]],dp[i-1][j]+s[j][a[i]]);
                    }
                    else
                    {
                        for(int k=1; k<=m; k++)
                        {
                            dp[i][k] = max(dp[i][k],dp[i-1][j]+s[j][k]);
                        }
                    }
                }
            }
        }
        int ans = -999;
        for(int i=1; i<=m; i++)
        {
            ans = max(ans,dp[n][i]);
        }
        cout<<ans<<endl;
    }
return 0;
}
