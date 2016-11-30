#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 105
#define INF (0x3f3f3f3f)

typedef long long ll;

struct Item{
    int p;
    int l;
    int x;
    int t[M];
    int v[M];

}item[M];

int map[M][M];
int m,n;


int dijkstra(int v0)
{
    int i,j;
    bool vis[M];
    int dis[M];
    memset(vis,false,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    int v0lv = item[v0].l;
    for(i=0; i<=n; i++)
    {
        if(item[i].l - v0lv <= m && item[i].l >= v0lv)//!!
            dis[i] = map[0][i];
    }
    vis[0] = true;
    for(i=0; i<n; i++)
    {
        int mindis = INF;
        int index;
        for(j=0; j<=n; j++)
        {
            if(!vis[j] && dis[j] < mindis)
            {
                mindis = dis[j];
                index = j;
            }
        }
        if(mindis == INF)
            break;
        vis[index] = true;

        for(j=0; j<=n; j++)
        {
            if(item[j].l - v0lv <= m && item[j].l>=v0lv)
            {
                dis[j] = min(dis[j],dis[index]+map[index][j]);

            }
        }
    }
    return dis[1];
}
int main()
{
    int i,j;
    while(~scanf("%d%d",&m,&n))
    {
        memset(map,INF,sizeof(map));//!!!!
        memset(item,0,sizeof(item));
        for( i=1; i<=n; i++)
        {
            scanf("%d%d%d",&item[i].p,&item[i].l,&item[i].x);
            for(j=0; j<item[i].x; j++)
            {
                scanf("%d%d",&item[i].t[j],&item[i].v[j]);
            }
            map[0][i] = item[i].p;
        }
        // build map
        for(i=1; i<=n; i++)
        {
            for(j=0; j<item[i].x; j++)
            {
                if(abs(item[i].l - item[item[i].t[j]].l)<=m)
                {
                    //map[i][item[i].t[j]] = min(map[i][item[i].t[j]],item[i].v[j]);
                    map[item[i].t[j]][i] = min(map[item[i].t[j]][i],item[i].v[j]);

                }
                //printf("%d->%d: %d==\t\t",item[i].t[j],i,map[item[i].t[j]][i]);
            }
        }
        //printf("\n");
        int ans = INF;
        for( i=1; i<=n; i++)
        {
            int tmp = dijkstra(i);
            ans = min(tmp,ans);
            //printf("%d = %d\n",i,tmp);
        }
        printf("%d\n",ans);
    }
return 0;
}
