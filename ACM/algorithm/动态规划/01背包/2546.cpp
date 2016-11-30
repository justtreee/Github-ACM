#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 50000

int dp[M],val[M];
int main()
{
    int n,m;
    int i,j;
    while(~scanf("%d",&n),n!=0)
    {
        memset(dp,0,sizeof(dp));

        for(i=0;i<n; i++)
        {
            scanf("%d",&val[i]);

        }
        scanf("%d",&m);
        sort(val,val+n);
        if(m<5)
        {
            printf("%d\n",m);
            continue;
        }
        for(i=0; i<n-1; i++)
        {
            for(j=m-5; j>=val[i]; j--)
            {
                dp[j] = max(dp[j],dp[j-val[i]]+val[i]);
            }
        }
        printf("%d\n",m-dp[m-5]-val[n-1]);

    }
return 0;
}
