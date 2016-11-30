#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 100
#define Mod 1000000007
int m,n;
int drt[8][2] = {{-1,0},{0,-1},{0,1},{1,0}};
char grid[M][M];
void DFS(int x,int y)
{
    int xx,yy;
    grid[x][y] = 'N';
    for(int i=0; i<8; i++)
    {
        xx = x + drt[i][0];
        yy = y + drt[i][1];
        if(xx>=m || yy>=n||xx<0||yy<0)
            continue;
        if(grid[xx][yy] == 'Y')
            DFS(xx,yy);
    }
}

long long mod(long long a,long long b,long long p)
{
    long long r,t;
    r = 1;
    t = a;
    while(b)
    {
        if(b%2 != 0)
        {
            r = (r * t)%p;
        }
        b >>=1;
        t = (t*t)%p;
    }
    return r;



    /*while(b--)
    {
        r = (a * r)%p;

    }
    return r;*/
}


int main()
{
    int i,j;
    int t;
    long long ans,fans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
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
                    if(grid[i][j] == 'Y')
                    {
                        DFS(i,j);
                        ans++;
                    }

                }
            }
            //printf("%d\n",ans);
            fans = mod(2,ans-1,Mod);
            printf("%d\n",fans);
        }

    }
return 0;
}

