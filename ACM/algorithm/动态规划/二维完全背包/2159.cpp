#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 120
struct node{
    int a,b;
}m[M];

int dp[M][M];
int main()
{
    int n,om,k,s;
    int pos;
    while(~scanf("%d%d%d%d",&n,&om,&k,&s))
    {
        memset(dp,0,sizeof(dp));
        for(int i=0; i<k; i++)
        {
            scanf("%d%d",&m[i].a,&m[i].b);
        }

        for(int i=0; i<k; i++)
        {
            for(int j=m[i].b; j<=om; j++)
            {
                for(int q=1; q<=s; q++)
                {
                    dp[j][q] = max(dp[j][q],dp[j-m[i].b][q-1]+m[i].a);
                }
            }
        }
        int flag = 0;
        for(int i= 0; i<=om; i++)
        {
            if(flag)
                break;
            for(int j=0; j<=s; j++)
            {
                if(dp[i][j] >= n)
                {
                    pos = i;
                    flag = 1;
                    break;
                }
            }
        }

        if(flag)
            printf("%d\n",om-pos);
        else
            printf("-1\n");



    }

return 0;
}

