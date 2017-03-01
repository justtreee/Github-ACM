#include <bits/stdc++.h>
using  namespace std;
const int M=55;
int T,r,c,a[M][M],vis[M][M];
struct node
{
    int x,y,h;
    friend bool operator < (node a,node b)
    {
        return a.h>b.h;
    }
};

bool visble(int x,int y)
{
    return (x>=1&&x<=r&&y>=1&&y<=c&&!vis[x][y]);
}

int xdir[] = {0,0,-1,1};
int ydir[] = {1,-1,0,0};
int main()
{
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int cas=1; cas<=T;cas++)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&r,&c);
        priority_queue<node> q;
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                scanf("%d",&a[i][j]);
                if((i==1||i==r||j==c||j==1)&&!vis[i][j])
                {
                    node t;
                    t.x=i;
                    t.y=j;
                    t.h=a[i][j];
                    q.push(t);
                    vis[i][j] = 1;
                }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            node tp = q.top();
            q.pop();
            for(int k=0; k<4; k++)
            {
                int xx = tp.x+xdir[k];
                int yy = tp.y+ydir[k];
                if(visble(xx,yy))
                {
                    if(a[xx][yy]>=tp.h)
                    {
                        node tmp;
                        tmp.x=xx;
                        tmp.y=yy;
                        tmp.h=a[xx][yy];
                        q.push(tmp);
                    }
                    else
                    {
                        ans+=tp.h-a[xx][yy];
                        a[xx][yy] = tp.h;
                        node tmp;
                        tmp.x=xx;
                        tmp.y=yy;
                        tmp.h=a[xx][yy];
                        q.push(tmp);
                    }
                    vis[xx][yy] = 1;
                }
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;


    }

    return 0;
}
