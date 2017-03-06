#include <bits/stdc++.h>
using namespace std;
const int M=505;
bool mp[M][M];
int in[M];
void topo(int n)
{
    priority_queue<int,vector<int>,greater<int> >que;
    for(int i=1; i<=n; i++)
    {
        if(!in[i])  que.push(i);
    }
    int cnt=1;
    while(!que.empty())
    {
        int u=que.top();
        que.pop();
        if(cnt!=n)
        {
            cout<<u<<" ";
            cnt++;
        }
        else
            cout<<u<<endl;
        for(int i=1; i<=n; i++)
        {
            if(!mp[u][i])
                continue;
            if(--in[i]==0)
            {
                que.push(i);
            }
        }
    }
}
int main()
{
    int n,m,u,v;
    cin>>n>>m;
    memset(mp,false,sizeof(mp));
    memset(in,0,sizeof(in));
    int k=0;
    for(int i=1; i<=m; i++)
    {
        cin>>u>>v;
        if(mp[u][v])
            continue;
        else
        {
            mp[u][v] = true;
            in[v]++;
        }
    }
    topo(n);

    return 0;
}
