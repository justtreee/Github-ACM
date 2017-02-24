#include <bits/stdc++.h>
using namespace std;
int n,m,d[100005],a[100005];
int f(int day)
{
    int cnt=0,done=0;
    int vis[100005];
    memset(vis,0,sizeof(vis));
    for(int i=day; i>=1;i--)
    {
        if(d[i])
        {
            if(vis[d[i]]==0)
            {
                vis[d[i]] = 1;
                cnt+=a[d[i]];
                done++;
            }
            else if(cnt!=0)
                cnt--;
        }
        else if(cnt!=0)
        {
            cnt--;
        }
    }
    if(cnt||done!=m)
        return 0;
    else
        return 1;
}
int main()
{

    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&d[i]);
    }
    for(int i=1; i<=m; i++)
    {
        scanf("%d",&a[i]);
    }
    int l=1,r=n,mid;

    while(l<r)
    {
        mid = l+(r-l)/2;
        if(f(mid)==0)
        {
            l = mid+1;
        }
        else
        {
            r = mid;
        }

    }
    if(f(l))    cout<<l<<endl;
    else
        cout<<-1<<endl;

    return 0;
}
