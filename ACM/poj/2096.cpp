#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
double dp[1008][1008];
double q,w,e,r;
int main()
{
    double n,s;
    while(cin>>n>>s)
    {
        memset(dp,0,sizeof dp);
        for(int i=n; i>=0; i--)
        {
            for(int j=s; j>=0; j--)
            {
                if(i == n && j == s)
                    continue;
                q=(n-i)*(s-j);
                w=(n-i)*j;
                e=i*(s-j);
                r=n*s-i*j;
                dp[i][j]=(q*dp[i+1][j+1]+w*dp[i+1][j]+e*dp[i][j+1]+n*s)/r;
            }
        }
//        for(int i=0; i<=n; i++)
//        {
//            for(int j=0;j<=s;j++)
//            {
//                cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        printf("%.4lf\n",dp[0][0]);
    }
    return 0;
}
