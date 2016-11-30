#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 100
int m,n;
int drt[8][2] = {{-1,0},{0,-1},{0,1},{1,0}};
char grid[M][M];
void DFS(int x,int y)
{
    int xx,yy;
    grid[x][y] = '*';
    for(int i=0; i<4; i++)
    {
        xx = x + drt[i][0];
        yy = y + drt[i][1];
        if(xx>=m || yy>=n||xx<0||yy<0)
            continue;
        if(grid[xx][yy] == '@')
            DFS(xx,yy);
    }
}
int main()
{
    int ans,i,j;
    while(~scanf("%d%d",&m,&n),m)
    {
        for(i=0; i<m; i++)
        {
            scanf("%s",grid[i]);
        }
        ans =0;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(grid[i][j] == '@')
                 {
                     DFS(i,j);
                     ans++;
                 }

            }
        }
        printf("%d\n",ans);
    }
return 0;
}
