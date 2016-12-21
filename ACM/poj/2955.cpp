//Çø¼ädp
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dp[102][102];
int main()
{
    string s;
    while(cin>>s&&s[0]!='e')
    {
        memset(dp,0,sizeof(dp));
        int len= s.size();
        for(int k=1;k<len;k++)
        {
            for(int i=0,j=k;j<len;i++,j++)
            {
                if(s[i]=='('&&s[j]==')'||s[i]=='['&&s[j]==']')
                    dp[i][j]=dp[i+1][j-1]+2;
                for(int x=i;x<j;x++)
                    dp[i][j]=max(dp[i][j],dp[i][x]+dp[x+1][j]);
            }
        }
        cout<<dp[0][len-1]<<endl;
    }
    return 0;
}
