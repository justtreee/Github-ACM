#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 999999
int map[505][505];
int dis[505];
using namespace std;
int main()
{
    int t,n,pos,minn,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans = -1;
        memset(dis,0,sizeof(dis));
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        for(int i=0; i<n; i++)
        {
            dis[i] = map[0][i];
        }
        for(int i=0; i<n-1; i++)
        {
            minn = inf;
            for(int j=0; j<n; j++)
            {
                if(minn>dis[j] && dis[j])
                {
                    minn = dis[j];
                    pos = j;
                }
            }

            if(ans < minn )
            {
                //printf("ans = minn = ",minn);
                ans = minn;
            }
            dis[pos] = 0;
            for(int j=0; j<n; j++)
            {
                if(dis[j] > map[pos][j])
                {
                    dis[j] = map[pos][j];
                }
            }
        }

        printf("%d\n",ans);
    }



    return 0;
}
