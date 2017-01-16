#include <bits/stdc++.h>
using namespace std;
const int M=10006;
int pre[M],a[M];
int find(int a)
{
    return pre[a]==a?a:pre[a]=find(pre[a]);
}
int unionx(int a,int b)
{
    int fa,fb;
    fa = find(a);
    fb = find(b);
    if(fa != fb)
        pre[fa] = fb;
}
void init(int n)
{
    for(int i=1; i<=n; i++)
    {
        pre[i] = i;
    }
}
int main()
{
    int n;
    cin>>n;
    init(n);
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=n; i++)
    {
        unionx(i,a[i]);
    }
    int ans = 0;
    for(int i=1; i<=n ;i++)
    {
        if(pre[i]==i)
            ans++;
    }
//    for(int i=1; i<10; i++)
//    {
//        cout<<pre[i]<<" ";
//    }
    //cout<<endl;
    cout<<ans<<endl;
    return 0;
}
