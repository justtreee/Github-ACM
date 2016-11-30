#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int M=1000;
int val[M],vlm[M],dp[M];
int main()
{
    int t,n,v;
    int i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&v);
        for(i=0; i<n; i++)
        {
            scanf("%d",&val[i]);
        }
        for(i=0; i<n; i++)
        {
            scanf("%d",&vlm[i]);
        }
        memset(dp,0,sizeof(dp));
        for(i=0; i<n; i++)
        {
            for(j=v; j>=vlm[i]; j--)
            {
                dp[j] = max(dp[j-vlm[i]]+val[i],dp[j]);
            }
        }
        printf("%d\n",dp[v]);
    }
    return 0;
}
