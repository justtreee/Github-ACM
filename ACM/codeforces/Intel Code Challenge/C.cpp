#include <bits/stdc++.h>
using namespace std;
const int M=1e5+10;
long long pre[M],a[M],b[M],ans[M],vis[M],n,sum[M],tmp;

int findx(int a)
{
    return pre[a]==a?a:pre[a]=findx(pre[a]);
}
void unionx(int a,int b)//b is a's father
{
    int fa,fb;
    fa = findx(a);
    fb = findx(b);

    pre[fa] = fb;
    sum[fb] += sum[fa];
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum[i] = a[i];
        pre[i] = i;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
    }
    tmp = 0;
    for(int i=n; i>1; i--)
    {
        vis[b[i]] = 1;
        if(vis[b[i]-1])
            unionx(b[i]-1,b[i]);
        if(vis[b[i]+1])
            unionx(b[i]+1,b[i]);
        tmp = max(tmp,sum[findx(b[i])]);
        ans[i-1] = tmp;
    }
    for(int i=1; i<=n; i++)
    {
        cout<<ans[i]<<endl;

    }
    return 0;
}
