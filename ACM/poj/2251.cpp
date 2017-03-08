#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int M=40;
int dir[6][3]= {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int l,r,c;
char mp[M][M][M];
bool vis[M][M][M];
struct node
{
    int x,y,z,len;
};
node S,E;
bool check(node a)
{
    int x=a.x;
    int y=a.y;
    int z=a.z;
    if(!(x>=0&&x<l&&y>=0&&y<r&&z>=0&&z<c))
        return false;
    else if(vis[x][y][z])
        return false;
    else if(mp[x][y][z]=='#')
        return false;
    return true;
}
int BFS()
{
    node u,next;
    S.len=0;
    vis[S.x][S.y][S.z] = true;
    queue<node>Q;
    Q.push(S);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        if(u.x==E.x&&u.y==E.y&&u.z==E.z)
            return u.len;
        for(int i=0; i<6; i++)
        {
            next.x = u.x+dir[i][0];
            next.y = u.y+dir[i][1];
            next.z = u.z+dir[i][2];
            if(!check(next))
                continue;
            vis[next.x][next.y][next.z] = true;
            next.len = u.len+1;
            Q.push(next);
        }
    }
    return 0;
}
int main()
{
    while(~scanf("%d%d%d",&l,&r,&c)&&l&&r&&c)
    {
        for(int i=0; i<l; i++)
        {
            for(int j=0; j<r; j++)
            {
                scanf("%s",mp[i][j]);
                for(int k=0; k<c; k++)
                {
                    if(mp[i][j][k]=='S')
                    {
                        S.x=i;
                        S.y=j;
                        S.z=k;
                    }
                    if(mp[i][j][k]=='E')
                    {
                        E.x=i;
                        E.y=j;
                        E.z=k;
                    }

                }
            }
        }

        memset(vis,false,sizeof(vis));
        int ans = BFS();
        if(!ans)
            printf("Trapped!\n");
        else
        {
            printf("Escaped in %d minute(s).\n",ans);
        }
    }

    return 0;
}
