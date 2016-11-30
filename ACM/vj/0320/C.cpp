#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M1 5005
#define M2 255000
int val[M1],dp[M2];

int main()
{
    int i,j,k;
    int n,len,sum,v,m;
    while(~scanf("%d",&n),n>0)//only ",n)" -> TLE
    {
        memset(val,0,sizeof(val));
        memset(dp,0,sizeof(dp));
        len = 0;
        sum = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&v,&m);
            while(m--)
            {
                val[len++] = v;
                sum += v;
            }
        }
        for(i=0; i<len; i++)
        {
            for(j=sum/2; j>=val[i]; j--)
            {
                dp[j] = max(dp[j],dp[j-val[i]]+val[i]);
            }
        }
        printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
    }

return 0;
}
