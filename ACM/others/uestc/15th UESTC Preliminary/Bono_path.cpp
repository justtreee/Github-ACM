#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
vector <int> mp[M];
long long dp[M][3];
long long ans=0;
int n,a[M];
void dfs(int u,int f)
{
    //cout<<u<<".size="<<mp[u].size()<<endl;
    for(int i=0 ; i<mp[u].size(); i++)
    {
        int v = mp[u][i];
        if(v==f)    continue;

        dfs(v,u);
        if(a[v]<a[u])
        {
            ans+=(dp[u][2]+dp[u][0])*(dp[v][1]+dp[v][0]+1);
            dp[u][1] += dp[v][1]+dp[v][0]+1;
        }
        else if(a[v]>a[u])
        {
            ans+=(dp[u][1]+dp[u][0])*(dp[v][2]+dp[v][0]+1);
            dp[u][2] += dp[v][2]+dp[v][0]+1;
        }
        else
        {
            ans+=dp[u][0]*(dp[v][0]+1+dp[v][1]+dp[v][2])
                +dp[u][1]*(dp[v][2]+dp[v][0]+1)
                +dp[u][2]*(dp[v][1]+dp[v][0]+1);
            dp[u][0] += dp[v][0] +1;
            dp[u][1] += dp[v][1];
            dp[u][2] += dp[v][2];
        }


    }
    ans+=dp[u][0]+dp[u][1]+dp[u][2];
//    for(int i=1; i<=n; i++)
//    {
//        cout<<"ans = "<<ans<<" "<<i<<" = "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
//    }
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    dfs(1,0);
    cout<<ans<<endl;

    return 0;
}
