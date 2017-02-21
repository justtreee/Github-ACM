#include <bits/stdc++.h>
using namespace std;
long long len=2,ans=0,l,r;
long long getlen(long long n)
{
    long long res=2;
    while(n>1)
    {
        res*=2;
        n/=2;
    }
    res-=1;
    return res;
}
void dfs(long long n,long long ll,long long rr)
{
    long long pos = (ll+rr)/2;
    if(ll>r||rr<l||ll>rr)   return;
    if(pos>=l&&pos<=r)
        ans+=n%2;
    dfs(n/2,ll,pos-1);
    dfs(n/2,pos+1,rr);
}
int main()
{
    long long n;
    cin>>n>>l>>r;
    //cout<<getlen(n)<<endl;
    dfs(n,1,getlen(n));
    cout<<ans<<endl;

    return 0;
}
