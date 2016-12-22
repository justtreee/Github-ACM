#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;
const int M = 2*1e5+5;
const int INF = (0x3f3f3f3f)*2;//3f3f3f3f->WA
typedef long long ll;
const double PI = acos(-1.0);
bool vis[M];   int n;ll dp[M];
vector<int>g[M];
ll sum[M];
ll val[M];
ll ans = -INF;
void dfs(int u)
{
    vis[u]=1;
    sum[u] = val[u];
    for(int i = 0; i<g[u].size(); i++)
    {
        ll v = g[u][i];
        if(vis[v]) continue;
        dfs(v);
        sum[u] += sum[v];
        //if(dp[u]!=-INF)
        ans = max(ans,dp[u]+dp[v]);
        dp[u] = max(dp[u],dp[v]);

    }
    dp[u] = max(dp[u], sum[u]);
}
int main()
{
    cin>>n;
    memset(dp,-INF,sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
	    cin>>val[i];
	}
    for(int i = 1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int flag = 0;
    for(int i=1; i<=n; i++)
    {
        ll tmp = g[i].size();
        if(i==1)    tmp++;
        if(tmp>2)
        {
            flag =1;
            break;
        }
    }
    if(!flag)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    dfs(1);
    if(ans==-INF)
        cout << "Impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}
