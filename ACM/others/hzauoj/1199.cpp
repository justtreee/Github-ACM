#include <bits/stdc++.h>
using namespace std;
const int M=100005;
long long  dp[M];
int main()
{
    int T,n,d;
    cin>>T;
    while(T--)
    {
        long long  mx = 0,ans = 0;
        cin>>n>>d;
        for(int i=1; i<=n; i++)
        {
            cin>>dp[i];
            dp[i] = dp[i]+mx;
            ans= max(dp[i],ans);
            if(i>d)
                mx = max(dp[i-d],mx);
        }
        cout<<ans<<endl;
    }

    return 0;
}
