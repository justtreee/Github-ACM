#include <bits/stdc++.h>
using namespace std;
const int M=100010;
const int INF = 0x3f3f3f3f;

struct edge
{
    int from,to,w,next;
} e[M*5];
int head[M],dist[M],lay[M];
bool vis[M];
int n,t,C;
vector<int>vec[M];

void add(int i,int j,int w)
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
    memset(dist,-1,sizeof(dist));///////
    memset(vis,false,sizeof(vis));
    q.push(s);
    dist[s]=0;
    int u,v;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u]; i!=-1; i=e[i].next)
        {
            v=e[i].to;
            if(dist[v]<0||dist[v]>dist[u]+e[i].w)/////
            {
                dist[v]=dist[u]+e[i].w;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        //between 2 layers
        if(lay[u]>1)//...3>>2>>1
        {
            int k = lay[u]-1;
            int siz = vec[k].size();
            for(int i=0; i<siz; i++)
            {
                v = vec[k][i];//choose a point named v from k-th layer
                if(dist[v]<0||dist[v]>dist[u]+C)///////////
                {
                    dist[v]=dist[u]+C;
                    if(!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);//push a point from a layer
                    }
                }
            }
        }
        if(lay[u]<n)
        {
            int k = lay[u]+1;
            int siz = vec[k].size();
            for(int i=0; i<siz; i++)
            {
                v = vec[k][i];
                if(dist[v]<0||dist[v]>dist[u]+C)/////////////
                {
                    dist[v] = dist[u]+C;
                    if(!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }


}
int main()
{
    int T,m,cas=1;
    int u,v,w;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&C);
        memset(head,-1,sizeof(head));
        memset(vis,false,sizeof(vis));
        t = 0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&lay[i]);
            vec[i].clear();//init

        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
            if(!vis[u])
            {
                vec[lay[u]].push_back(u);
                vis[u] = true;
            }
            if(!vis[v])
            {
                vec[lay[v]].push_back(v);
                vis[v] = true;
            }
        }
        if(!vis[1])
            vec[lay[1]].push_back(1);
        if(!vis[n])
            vec[lay[n]].push_back(n);
        for(int i=1; i<=n; i++)
        {
            if(vec[lay[i]].empty())
                vec[lay[i]].push_back(i);
        }
        spfa(1);
        printf("Case #%d: %d\n",cas++,dist[n]);
    }

    return 0;
}
