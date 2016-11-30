#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 10010
typedef long long ll;
int main()
{
    int t,n;
    int dp[M];
    int vlm[3] = {150,200,350};//vlm==val
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=0; i<3; i++)
        {
            for(int j=vlm[i]; j<=n; j++)
            {
                dp[j] = max(dp[j],dp[j-vlm[i]]+vlm[i]);
            }
        }
        printf("%d\n",n-dp[n]);
    }
return 0;
}
