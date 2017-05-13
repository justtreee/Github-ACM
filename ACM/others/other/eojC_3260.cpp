#include <bits/stdc++.h>
using namespace std;
int vis[10][10];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n,m,ix,iy,k,flag=0;
void DFS(int x,int y,int dis)
{
    int sum = 0;
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<m;j++)
//        {
//            cout<<vis[i][j];
//        }cout<<endl;
//    }cout<<endl;
    for(int i=0; i<4; i++)
    {
        int xx= x+dx[i];
        int yy = y+dy[i];
        if(xx<0||yy<0)    continue;
        sum+=vis[xx][yy];
    }
    if(sum>1)//avoid circle
        return;
    if(x==ix&&y==iy)
    {
        if(dis>=k)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(vis[i][j]==1)
                        cout<<".";
                    else
                        cout<<"*";
                }cout<<endl;
            }
            flag = 1;
        }
        return ;
    }
    if(flag)
        return ;
    for(int i=0; i<4; i++)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(!vis[xx][yy]&&xx>=0&&xx<n&&yy>=0&&yy<m)
        {
            vis[xx][yy] = 1;
            DFS(xx,yy,dis+1);
            vis[xx][yy] = 0;
            if(flag == 1)
                return ;
        }
    }
}
int main()
{

    cin>>n>>m>>ix>>iy>>k;
    ix--;iy--;
    memset(vis,0,sizeof(vis));
    vis[0][0] = 1;
    DFS(0,0,0);

    return 0;
}
