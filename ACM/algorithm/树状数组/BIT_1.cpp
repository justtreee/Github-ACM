#include <bits/stdc++.h>
using namespace std;
int n,m,num[10000],t[20000],l,r;
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int p)
{
    while(x<=n)
    {
        t[x] += p;
        x+=lowbit(x);
    }
}
int sum(int k)
{
    int res = 0;
    while(k>0)
    {
        res+=t[k];
        k-=lowbit(k);
    }
    return res;
}
int query(int l,int r)
{
    return sum(r) - sum(l-1);
}
int main()
{
    cin>>n>>m;
    memset(num,0,sizeof(num));
    for(int i=1; i<=n; i++)
    {
        cin>>num[i];
        add(i,num[i]);
    }
    for(int i=1; i<=m; i++)
    {
        cin>>l>>r;
        cout<<query(l,r)<<endl;
    }
    return 0;
}
