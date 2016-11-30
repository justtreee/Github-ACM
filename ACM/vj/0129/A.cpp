#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
char map[21][21];
bool mark[21][21];
int drt[4][2] = {-1,0,1,0,0,1,0,-1};//direct:left;right;up;down;

int ans;
int w,h;

void dfs(int x, int y)
{
    int k,fx,fy;
    mark[x][y] = true;
    for(k=0; k<4; k++)
    {
        fx = x + drt[k][0];
        fy = y + drt[k][1];
        if(fx >= 0 && fy >= 0 && fx < h && fy < w && !mark[fx][fy] && map[fx][fy] != '#')
        {
            ans++;
            dfs(fx,fy);
        }
    }
    return;
}
int main()
{
    int ox,oy;
    int i,j;
    while(cin>>w>>h && (w||h))
    {
        memset(mark,false,sizeof(mark));//mark = 1 or 0 -> wrong
        for(i=0; i<h; i++)
        {
            for(j=0; j<w; j++)
            {
                cin>>map[i][j];//scanf -> wrong
                if(map[i][j] == '@')
                {
                    ox = i;
                    oy = j;
                }
            }
        }
        ans = 1;
        dfs(ox,oy);
        printf("%d\n",ans);

    }
return 0;
}
