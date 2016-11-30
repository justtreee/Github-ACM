#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 120
int main()
{
    char s[M];
    int dp[2][M];//0 is unCaps, 1 is caps
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%s",s);
        int len = strlen(s);
        dp[1][0] = 1;//Caps
        for(int i=0; i<len; i++)
        {
            if(s[i] <= 'Z' && s[i] >= 'A')
            {
                dp[0][i+1] = min(dp[0][i]+2,dp[1][i]+2);
                dp[1][i+1] = min(dp[0][i]+2,dp[1][i]+1);
            }
            else
            {
                dp[0][i+1] = min(dp[0][i]+1,dp[1][i]+2);
                dp[1][i+1] = min(dp[0][i]+2,dp[1][i]+2);
            }
        }
        printf("%d\n",min(dp[0][len],dp[1][len]+1));
    }
return 0;
}

