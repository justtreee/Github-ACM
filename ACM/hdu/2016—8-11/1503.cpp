#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string a,b;
int dp[1000][1000],mark[1000][1000];

void LCS()
{
    memset(dp,0,sizeof(dp));
    for(int i=0; i<=a.size();i++)
    {
        mark[i][0]=1;
    }
    for(int i=0; i<=b.size();i++)
    {
        mark[0][i]=-1;
    }
    for(int i=1; i<=a.size();i++)
    {
        for(int j=1; j<=b.size(); j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                mark[i][j] = 0;
            }
            else if(dp[i-1][j]>=dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                mark[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i][j-1];
                mark[i][j] = -1;
            }
        }
    }
}

void out(int i,int j)
{
    if(i==0&&j==0)
        return ;
    if(mark[i][j]==0)
    {
        out(i-1,j-1);
        cout<<a[i-1];
    }
    else if(mark[i][j]==1)
    {
        out(i-1,j);
        cout<<a[i-1];
    }
    else
    {
        out(i,j-1);
        cout<<b[j-1];
    }
}
int main()
{
    while(cin>>a>>b)
    {
        LCS();
        out(a.size(),b.size());
        cout<<endl;
    }

    return 0;
}
