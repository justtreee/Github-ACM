#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 1005
typedef long long ll;
int dp[2*M];
int main()
{
    int t,m,n,w[M],a[M],b[M];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d",&w[i],&a[i],&b[i]);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=m; j>=w[i]; j--)
            {
                dp[j] = max(dp[j],dp[j-w[i]]+a[i]+b[i]);//ai+bi
            }
            for(int j=w[i]; j<=m; j++)
            {
                dp[j]=max(dp[j],dp[j-w[i]]+a[i]);//ai*x+bi
            }

        }
        printf("%d\n",dp[m]);
    }
return 0;
}
