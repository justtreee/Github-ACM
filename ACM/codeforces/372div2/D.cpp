#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
#include <queue>
using namespace std;
#define M 10005
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);

struct edge
{
    int from,to,next;
    ll w;
}e[M*2];
int head[M];
bool vis[M];
int dist[M];
int t;
void add(int i,int j,ll w)
{
    e[t].from=i;
    e[t].to=j;
    e[t].w=w;
    e[t].next=head[i];
    head[i]=t++;
}
void spfa(int s)
{
    queue <int> q;
    for(int i=0;i<M;i++)//WA!.....(0,M-1)instead of (1,M)
        dist[i]=INF;
    memset(vis,false,sizeof(vis));
    q.push(s);
    vis[s] = true;//ppppp
    dist[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            if(dist[v]>dist[u]+e[i].w)
            {
                dist[v]=dist[u]+e[i].w;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
}
int n,m,s,tt;
ll l;
int mark[M];
int main()
{

    cin>>n>>m>>l>>s>>tt;

    memset(head,-1,sizeof(head));
    memset(mark,0,sizeof(mark));
    t=0;
    for(int i=0; i<m; i++)
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        if(w==0)
        {
            w=1;//not less than 1
            mark[i]=1;
        }
        add(u,v,w);
        add(v,u,w);
    }
    spfa(s);

    if(dist[tt]==INF||dist[tt]>l)
    {
        //cout<<dist[tt]<<endl;
        cout<<"NO"<<endl;
        return 0;
    }
    ll tmp = l-dist[tt];
    int flag = 0;
    if(dist[tt]==l)
        flag = 1;
    if(!flag)
    {
        for(int i=0; i<m; i++)
        {
            if(mark[i])
            {
                e[i*2].w+=tmp;
                e[i*2+1].w+=tmp;
                spfa(s);
                if(dist[tt]==l)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    tmp = l-dist[tt];
                }
            }
        }
    }
    if(!flag)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=0; i<m ;i++)
        {
            cout<<e[i*2].from<<" "<<e[i*2].to<<" "<<e[i*2].w<<endl;
        }
    }


return 0;
}
