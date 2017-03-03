#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n,m,k;
int mp[40][40],link[1500];
vector<int>G[1500];
bool vis[1500];
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

bool dfs(int u)
{
    for(int i=0; i<G[u].size(); i++)
    {
        int t=G[u][i];
        if(!vis[t])
        {
            vis[t]=1;
            if(link[t]==-1||dfs(link[t]))
            {
                link[t]=u;
                return true;
            }
        }
    }
    return false;
}
int match(int cnt)
{
    int num=0;
    for(int i=1; i<=cnt; i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i))
            num++;
    }
    return num;
}
int main()
{

    while(~scanf("%d%d%d",&n,&m,&k))
    {
        memset(mp,0,sizeof(mp));
        for(int i=0; i<k; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            mp[v][u]=-1;
        }
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(mp[i][j]==0)
                {
                    mp[i][j]=++cnt;
                }
            }
        }
        if(cnt%2==1)
            printf("NO\n");
        else
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=m; j++)
                {
                    if(mp[i][j]!=-1)
                    {
                        for(int k=0; k<4; k++)
                        {
                            int x=i+dx[k],y=j+dy[k];
                            if(x>=1&&x<=n&&y>=1&&y<=m&&mp[x][y]!=-1)
                            {
                                G[mp[i][j]].push_back(mp[x][y]);
                                G[mp[x][y]].push_back(mp[i][j]);
                            }
                        }
                    }
                }
            }
            memset(link,-1,sizeof(link));
            int num=match(cnt);
            if(num==cnt) printf("YES\n");
            else printf("NO\n");
        }
        for(int i=0; i<1500; i++)
            G[i].clear();
    }
}
