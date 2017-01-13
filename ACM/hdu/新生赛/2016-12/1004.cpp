#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;
const int M = 1000;
const int INF = (0x3f3f3f3f);
typedef long long ll;
const double PI = acos(-1.0);
int main()
{
    int T,n,m;
    string s;
    int F,I,D,E;
    cin>>T;
    while(T--)
    {
        F=I=D=E=0;
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            if(s[0]=='F')   F++;
            if(s[0]=='I')   I++;
            if(s[0]=='D')   D++;
            if(s[0]=='E')   E++;
        }
        int val[15];
        int cost[15];
        int dp[100];
        int tmp=0,ans=0;
        val[0] = 0; cost[0] = 0;
        memset(val,0,sizeof(val));
        memset(cost,0,sizeof(cost));
        //cout<<":::"<<D<<E<<F<<I<<endl;
        for(int cd=0; cd<=D; cd++)
        {
            for(int ce=0; ce<=E; ce++)
            {
                for(int i=1; i<=I; i++)
                {
                    val[i] = 3+ce*2+cd;
                    cost[i] = 2;
                }
                for(int i=I+1; i<=I+F; i++)
                {
                    val[i] = 6+ce*2+cd;
                    cost[i] = 4;
                }
                int v=10-ce*4-cd*2;
                memset(dp,0,sizeof(dp));
                for(int i=0; i<=I+F; i++)
                {
                    for(int j=v; j>=cost[i]; j--)
                    {
                        dp[j] = max(dp[j-cost[i]]+val[i],dp[j]);
                    }
                }
                tmp = dp[v];
                ans = max(ans,tmp);
            }
            ans = max(ans,tmp);
        }
        ans = max(ans,tmp);
        //cout<<ans<<endl;
        if(ans>=m)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }

    return 0;
}

