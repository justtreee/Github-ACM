#include <iostream>
#include <cstring>
#include <cstdio>
#define inf 99999999
using namespace std;
int map[1005][1005];
int d[1005];
int p[1005];
int vis[1005];
int n,m;
void dijkstra(int f)
{
    int i;
    for(i=0;i<=n;i++)
        d[i]=inf;
    d[1]=0;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
    {
        int y,x,m=inf;
        for(y=1;y<=n;y++)
            if(!vis[y]&&d[y]<m)
                m=d[x=y];
        vis[x]=1;
        for(y=1;y<=n;y++)
        {
            if(d[y]>d[x]+map[x][y])
            {
                d[y]=d[x]+map[x][y];
                if(f)
                    p[y]=x;
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
            {
                if(i==j)
                    map[i][j]=0;
                else
                    map[i][j]=inf;
            }
        memset(p,0,sizeof(p));
        for(i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(w<map[u][v])
                //map[v][u]=map[u][v]=w;
                map[u][v]=w;
        }

        if(map[1][n] == inf)
        {
            printf("-1\n");
            continue;
        }
        if(map[1][n] == map[n][1])
        {
            printf("INF\n");
            continue;
        }

        dijkstra(1);
        int maxx=d[n];

        for(int i=1; i<n-1; i++)
        {
            if(map[i][i+1]>map[i+1][i+2])
            {
                map[i][i+1] = inf;
                map[i+1][i+2] = inf;
                dijkstra(0);
            }
        }

        for(i=n;i!=1;i=p[i])
        {
            int t=map[i][p[i]];
            map[i][p[i]]=inf;
            map[p[i]][i]=inf;
            dijkstra(0);
            if(d[n]>maxx && d[n] != inf)
            {
                maxx=d[n];
            }
            map[i][p[i]]=map[p[i]][i]=t;
        }



        printf("%d\n",maxx);



    }

    return 0;
}
