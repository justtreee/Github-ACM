//shorter templet of max flow
//http://blog.csdn.net/tengfei461807914/article/details/52202621

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 100500;
struct Edge{
    int to,cap,rev;
};
vector <Edge> G[MAXN];
bool used[MAXN];
void addedge(int from,int to,int cap)
{
    G[from].push_back((Edge){to,cap,G[to].size()});
    G[to].push_back((Edge){from,0,G[from].size()-1});
}
int dfs(int v,int t,int f)
{
    if(v== t)
        return f;
    used[v] = true;
    for(int i=0; i<G[v].size(); i++)
    {
        Edge &e = G[v][i];
        if(!used[e.to] && e.cap>0)
        {
            int d = dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;

            }
        }
    }
    return 0;
}

int maxflow(int s,int t)
{
    int flow = 0;
    for(;;)
    {
        memset(used,false,sizeof(used));
        int f = dfs(s,t,INF);
        if(f == 0)
            return flow;
        flow += f;
    }
}

void init(int n)
{
    for(int i=0; i<n; i++)
    {
        G[i].clear();
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

        init(m);
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            addedge(u,v,w);

        }
        cout<<maxflow(1,n)<<endl;


    return 0;
}
