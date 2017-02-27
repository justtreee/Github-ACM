#include <bits/stdc++.h>
using namespace std;
string t,p;int lent,lenp,a[200005];
int vis[200005];
bool bin(int x)
{
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=x; i++)
    {
        vis[a[i]-1] = 1;
    }
    int j=0;
    for(int i=0; i<lent; i++)
    {
        if(vis[i]==1)   continue ;
        if(t[i]==p[j])
        {
            j++;
        }
        if(j==lenp)
            return true;
    }
    return false;

}
int main()
{
    cin>>t>>p;
    lent = t.size();lenp=p.size();
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=lent;i++)
    {
        scanf("%d",&a[i]);
    }
    int l=1,r=lent,mid;
    int ans=0;
    while(l<r)
    {
        mid = l+(r-l)/2;
        if(bin(mid))
        {
            l=mid+1;
            ans = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout<<ans<<endl;

    return 0;
}
