#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn=500+5;
const int maxe=6000+5;
const int INF=0x7fffffff;

struct edge
{
    int v,w;
    int next;
};

edge e[maxe];
int dis[maxn],vis[maxn],f,n,m,w,head[maxe],cnt[maxn];
int k;
void add(int u,int v,int w)
{
    e[k].v=v;
    e[k].w=w;
    e[k].next=head[u];
    head[u]=k++;
}

bool spfa(int s)
{
    queue<int> q;
    vis[s]=1;
    dis[s]=0;
    cnt[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u]; i!=-1; i=e[i].next)
        {
            int v=e[i].v;
            if(dis[u]+e[i].w<dis[v])
            {
                dis[v]=dis[u]+e[i].w;
                if(!vis[v])
                {
                    cnt[v]++;
                    if(cnt[u]>=n)
                        return false;
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    return true;
}
void init()
{
    k=0;
    memset(head,-1,sizeof(head));
    for(int i=0; i<=n; i++)
    {
        dis[i]=INF;
    }
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
}
int main()
{
    while(cin>>f)
    {
        while(f--)
        {
            cin>>n>>m>>w;
            init();
            int s,e,val;
            for(int i=0; i<m; i++)
            {
                cin>>s>>e>>val;
                add(s,e,val);
                add(e,s,val);
            }
            for(int i=0; i<w; i++)
            {
                cin>>s>>e>>val;
                add(s,e,0-val);
            }
            if(spfa(1))
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
    }
}
