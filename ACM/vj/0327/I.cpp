/*#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 205

struct poit{
    double x,y;
}stone[M];

double dis[M][M];
int main()
{
    int t;
    int ca = 0;
    while(~scanf("%d",&t),t>0)
    {
        for(int i=1; i<=t; i++)
        {
            scanf("%lf%lf",&stone[i].x,&stone[i].y);
        }
        for(int i=1; i<=t-1; i++)
        {
            for(int j=i+1; j<=t; j++)
            {
                double dx = stone[i].x-stone[j].x;
                double dy = stone[i].y-stone[j].y;
                dis[i][j] = dis[j][i] = sqrt(dx*dx + dy*dy);
            }
        }

        for(int k=1;k<=t; k++)
        {
            for(int i=1; i<=t-1; i++)
            {
                for(int j=i+1; j<=t; j++)
                {
                    if(dis[i][k]<dis[i][j] &&dis[j][k]<dis[i][j])
                    {
                        if(dis[i][k]<dis[j][k])
                            dis[i][j] = dis[j][i] = dis[j][k];
                        else
                            dis[i][j] = dis[j][i] = dis[i][k];
                    }
                }
            }
        }
        ca++;
        printf("Scenario #%d\n",ca);
        printf("Frog Distance = %.3lf\n\n",dis[1][2]);
    }
return 0;
}
//WA!

*/


#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 220
int n;
double dis[M][M],temp[M];
struct pos{
    double x,y;
}stone[M];

double cal(int i,int j)
{
    return (sqrt(pow(stone[i].x-stone[j].x,2)+pow(stone[i].y-stone[j].y,2)));
}

double dijkstra()
{
    int vis[M];
    memset(vis,0,sizeof(vis));
    temp[0] = 0;
    vis[0] = 1;
    for(int i=0; i<n; i++)
    {
        temp[i] = dis[0][i];
    }
    for(int i=0; i<n-1; i++)
    {
        double m = 99999;
        int p,q;
        for(q=0; q<n; q++)
        {
            if(!vis[q] && m>= temp[q])
                m = temp[p=q];

        }
        vis[p] = 1;
        for(q=0; q<n; q++)
        {
            if(!vis[q])
            {
                double maxx = max(temp[p],dis[p][q]);
                if(temp[q] > maxx)
                    temp[q] = maxx;
            }
        }

    }
    return temp[1];
}
int main()
{
    int cnt=1;
    while(~scanf("%d",&n),n>0)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%lf %lf",&stone[i].x,&stone[i].y);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                dis[i][j] = dis[j][i] = cal(i,j);
            }
            dis[i][i] = 0;
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",cnt++,dijkstra());
    }
return 0;
}


