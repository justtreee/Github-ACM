#include <iostream>
#include <cstdio>
using namespace std;
double dp[1010][1010];

int main()
{
    int n,s;
    while(cin>>n>>s)
    {
        dp[n][s] = 0;
        for(int i=n; i>=0; i--)
        {
            for(int j=s; j>=0; j--)
            {
                if(i==n&&j==s)  continue;
                dp[i][j] = (i*(s-j)*dp[i][j+1]+(n-i)*j*dp[i+1][j]+(n-i)*(s-j)*dp[i+1][j+1]+n*s)/(n*s-j*i);
            }
        }
        printf("%.4f\n",dp[0][0]);
    }

    return 0;
}
