#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int M=1005;
double rate[M][M],cost[M][M],dist[M];
int n,m,s;double vv;
int vis[M];
void spfa(int s,double vv)
{
    queue <int> q;
    memset(dist,0,sizeof(dist));
    memset(vis,0,sizeof(vis));
    q.push(s);
    dist[s] = vv;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u] = 0;
        for(int v=0; v<=n; v++)
        {
            //double tmp = (cost[u][v]);
            if(dist[v]<(dist[u]-cost[u][v])*rate[u][v])
            {
                dist[v] = (dist[u]-cost[u][v])*rate[u][v];
                if(dist[s]>vv)
                {
                    //cout<<dist[s]<<endl;
                    cout<<"YES"<<endl;
                    return;
                }
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    //cout<<dist[s]<<endl;
    cout<<"NO"<<endl;
}
void init()
{
    memset(rate,0,sizeof(rate));
    memset(cost,0,sizeof(cost));
    for(int i=1; i<=n; i++)
    {
        rate[i][i] = 1;
    }
}
int main()
{

    while(cin>>n>>m>>s>>vv)
    {
        init();
        for(int i=0; i<m; i++)
        {
            int a,b;    double rab,cab,rba,cba;
            cin>>a>>b>>rab>>cab>>rba>>cba;
            rate[a][b] = rab;
            rate[b][a] = rba;
            cost[a][b] = cab;
            cost[b][a] = cba;
        }
        spfa(s,vv);
    }
    return 0;
}
