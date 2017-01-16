#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 105
int pre[M],mark[M];
int is[M][M];

void init()
{
    for(int i; i<M; i++)
    {
        pre[i] = i;
    }
    memset(is,0,sizeof(is));
    memset(mark,0,sizeof(mark));
}
int find(int a)
{
    if(a == pre[a])
        return a;
    else
        return pre[a] = find(pre[a]);
}
void unionx(int a,int b)
{
    int fa,fb;
    fa = find(a);
    fb = find(b);
    if(fa != fb)
    {
        pre[fb] = fa;
    }
}
int main()
{
    int n,k;
    while(~scanf("%d %d",&n,&k))
    {
        init();
        int x,y;
        for(int i=1; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            unionx(x,y);
            is[x][y] = 1;
        }
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(is[i][k]==1 && is[k][j]==1)
                    {
                        is[i][j]=1;
                    }
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(pre[j]==pre[i] && i!=j && is[i][j] ==1)
                    mark[i]++;
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++)
        {
            if(mark[i]==k)
                ans++;
        }
        printf("%d\n",ans);
    }
return 0;
}
