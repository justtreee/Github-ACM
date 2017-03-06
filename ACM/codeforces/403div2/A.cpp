#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x[200005];
    scanf("%d",&n);
    memset(x,0,sizeof(x));
    int mx=0,ans=-1;
    for(int i=1 ;i<=2*n; i++)
    {int t;
        scanf("%d",&t);
        if(x[t]==0)
        {
            x[t]++;
            mx++;
            ans=max(mx,ans);
        }
        else
        {
            x[t]=0;
            mx--;
            ans=max(mx,ans);
        }

    }
    cout<<ans<<endl;
    return 0;
}

