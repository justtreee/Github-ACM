#include <bits/stdc++.h>
using namespace std;
const int M=1000005*2;
int a[M],pre[M],mp[M];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ans=-1;
        memset(mp,0,sizeof(mp));
        memset(pre,0,sizeof(pre));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            mp[min(a[i],1000001)]++;
        }
        pre[1] = mp[1];
        for(int i=2; i<=1000001; i++)
        {
            pre[i] = pre[i-1]+mp[i];
        }
        for(int i=1; i<=1000001; i++)
        {
            ans = max(ans,(pre[i]+i-1)/i);
        }
        cout<<ans<<endl;

    }
    return 0;
}
