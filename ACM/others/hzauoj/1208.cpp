#include <bits/stdc++.h>
using namespace std;
char mp[60][60];
int vis[60][60];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0 ,0};
int dfs(int x,int y,char ch,int fx,int fy)
{
    vis[x][y] = 1;
    for(int i=0; i<4; i++)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if((xx==fx&&yy==fy)||(mp[xx][yy]!=ch))
            continue;

        if(vis[xx][yy])
            return 1;
        if(dfs(xx,yy,ch,x,y)==1)
            return 1;
    }
    vis[x][y] = 0;
    return 0;
}

int main()
{int n,m;
    while(cin>>n>>m)
    {
        memset(vis,0,sizeof(vis));
    memset(mp,0,sizeof(mp));


    for(int i=1; i<=n; i++)
    {
        scanf("%s",mp[i]+1);
    }
    int flag = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char ch = mp[i][j];
            if(flag)
                break;
            if(dfs(i,j,ch,0,0))
                flag = 1;
        }

    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    }
    return 0;
}
