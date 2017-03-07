#include <bits/stdc++.h>
using namespace std;
const int M=505;
//vector <int> g[M];
int in[M],mp[M][M];
int n,m;
bool topo()
{
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=0; i<n; i++)
    {
        if(in[i]==0)  q.push(i);
    }
    int cnt=0;
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        cnt++;
        for(int i=0; i<n; i++)
        {
            if(mp[u][i]&&--in[i]==0)
                q.push(i);
        }
    }
    if(cnt!=n)
        return false;
    else
        return true;
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        memset(in,0,sizeof(in));
        memset(mp,0,sizeof(mp));
//        for(int i=0; i<=n; i++)
//        {
//            g[i].clear();
//        }
        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            mp[u][v] = 1;
            //g[u].push_back(v);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mp[i][j])    in[j]++;
            }
        }
        if(topo())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
