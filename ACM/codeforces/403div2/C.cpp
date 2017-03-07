#include <bits/stdc++.h>
using namespace std;
vector <int> g[200005];
int clr[200005],id[200005];
int ans=-1;
void dfs(int u,int fu,int ffu)
{
    int fc=0,ffc=0;
    if(fu) fc=clr[fu];
    if(ffu)ffc=clr[ffu];
    if(id[fu]==0)      id[fu]++;
    if(id[fu]==fc)     id[fu]++;
    if(id[fu]==ffc)    id[fu]++;
    if(id[fu]==fc)     id[fu]++;
    clr[u] = id[fu];
    ans = max(ans,clr[u]);
    id[fu]++;
    for(int i=0; i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=fu)
            dfs(v,u,fu);
    }
}
int main()
{
    int n,x,y;
    scanf("%d",&n);
    memset(clr,0,sizeof(clr));
    memset(id,0,sizeof(id));
    for(int i=0; i<=n; i++)
    {
        g[i].clear();
    }
    for(int i=1; i<n; i++)
    {
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0,0);
    cout<<ans<<endl;
    for(int i=1; i<=n ;i++)
    {
        cout<<clr[i]<<" ";
    }
    cout<<endl;

    return 0;
}


