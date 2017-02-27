#include <bits/stdc++.h>
using namespace std;
struct node{
    int a,b,dis;
}c[200005];
bool cmp(node a,node b)
{
    if(a.dis==b.dis)
        return a.a<b.a;
    return a.dis<b.dis;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n;i++)
    {
        scanf("%d",&c[i].a);
    }
    for(int i=0; i<n;i++)
    {
        scanf("%d",&c[i].b);
        c[i].dis = c[i].a-c[i].b;
    }
    sort(c,c+n,cmp);
    int ans=0;
    for(int i=0; i<k; i++)
    {
        ans+=c[i].a;
    }
    for(int i=k; i<n; i++)
    {
        ans+=min(c[i].a,c[i].b);
    }
    cout<<ans<<endl;



    return 0;
}
