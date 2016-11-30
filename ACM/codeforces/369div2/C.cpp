#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 105
#define INF 1e18
typedef long long ll;
const double PI = acos(-1.0);

ll dp[M][M][M];
ll c[M],p[M][M];
int n,m,kk;
int main()
{
    cin>>n>>m>>kk;
    for(int i=1; i<=n; i++)
    {
        cin>>c[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>p[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= n; k++){
                dp[i][j][k] = INF;
            }
        }
    }
    //memset(dp,INF,sizeof(dp));
    //cout<<"dp="<<dp[n][m-1][kk]<<endl;
    for(int i=1; i<=n; i++)
    {
        if(c[i]==0)
        {
            for(int j=1; j<=m; j++)
            {
                for(int k=1; k<=i; k++)
                {
                    if(k==1)
                        dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k]+p[i][j]);
                    else
                    {
                        dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k]+p[i][j]);
                        ll tmp = INF;
                        for(int q=1; q<=m; q++)
                        {
                            if(q==j) continue;
                            tmp = min(tmp,dp[i-1][q][k-1]+p[i][j]);
                        }
                        dp[i][j][k] = min(dp[i][j][k],tmp);
                    }
                    //cout<<"ci==0"<<endl;
                }
            }
        }
        else
        {
            for(int j=1; j<=m; j++)
            {
                for(int k=1; k<=i; k++)
                {
                    if(k==1)
                        dp[i][c[i]][k] = min(dp[i][c[i]][k],dp[i-1][c[i]][k]);
                    else
                    {
                        if(c[i]==j)
                            dp[i][c[i]][k] = min(dp[i-1][c[i]][k],dp[i][c[i]][k]);
                        else
                            dp[i][c[i]][k] = min(dp[i-1][j][k-1],dp[i][c[i]][k]);
                        //cout<<"!=0"<<endl;
                    }
                }
            }
        }
    }

    ll ans = INF;

    for(int i=1; i<=m; i++)
    {
        //cout<<"dp="<<dp[n][i][kk]<<endl;
        ans = min(ans,dp[n][i][kk]);
        //cout<<"cout: i="<<i<<"  ans="<<ans<<endl;
    }
    if(ans == INF)
        ans = -1;
    cout<<ans<<endl;
return 0;
}
