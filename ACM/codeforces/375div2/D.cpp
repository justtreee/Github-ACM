#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 60
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);
int m,n,kk;
int drt[4][2] = {{-1,0}
    ,{0,-1},{0,1},{1,0}
};
char grid[M][M];
int vis[M][M];
int flag=0;
int siz;
int cnt=0;
struct Lake
{
    int s,x,y;
} l[2600];
bool cmp(Lake a,Lake b)
{
    return a.s<b.s;
}

void DFS1(int x,int y)
{
    int xx,yy;
    siz++;
    vis[x][y] = 1;//grid[x][y] = '*';
    if(x==0||x==m-1||y==0||y==n-1)
        flag = 1;
    for(int i=0; i<4; i++)
    {
        xx = x + drt[i][0];
        yy = y + drt[i][1];
        if(xx>=m || yy>=n||xx<0||yy<0||vis[xx][yy]==1)
        {
            continue;
        }
        if(grid[xx][yy] == '.')
        {
            DFS1(xx,yy);
        }
    }
}
void DFS2(int x,int y)
{
    int xx,yy;
    grid[x][y] = '*';

    for(int i=0; i<4; i++)
    {
        xx = x + drt[i][0];
        yy = y + drt[i][1];
        if(xx>=m || yy>=n||xx<0||yy<0)
            continue;
        if(grid[xx][yy] == '.')
            DFS2(xx,yy);
    }
}

int main()
{


    int ans=0,i,j;
    cin>>m>>n>>kk;
    memset(vis,0,sizeof(vis));
    for(i=0; i<m; i++)
    {
        scanf("%s",grid[i]);
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            if(grid[i][j] == '.'&&!vis[i][j])
            {
                siz = 0;
                flag = 0;
                DFS1(i,j);
                if(flag)
                    continue;
                l[cnt].s = siz;
                l[cnt].x = i;
                l[cnt].y = j;
                cnt++;
            }
        }
    }
    sort(l,l+cnt,cmp);
    for(i=0; i<cnt-kk; i++)
    {
        ans+=l[i].s;
        DFS2(l[i].x,l[i].y);
    }

    cout<<ans<<endl;
    for(int i=0; i<m; i++)
    {
        printf("%s\n",grid[i]);
    }


    return 0;
}
