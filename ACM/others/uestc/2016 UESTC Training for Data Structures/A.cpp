#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 200000
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);
int a,b;
struct node{
    int l,r,mid;
    ll val;
}p[M*2];

void init(int l,int r,int o)
{
    p[o].l = l;
    p[o].r = r;
    p[o].mid = (l+r)/2;
    if(p[o].l==p[o].r)
        return ;
    init(l,p[o].mid,o*2);
    init(p[o].mid+1,r,o*2+1);
}

void damage(int o)
{
    if(p[o].l == p[o].r)
    {
        p[o].val += b;
        return ;
    }
    if(a<=p[o].mid)
        damage(o*2);
    else
        damage(o*2+1);
    p[o].val = max(p[o*2].val,p[o*2+1].val);


}

ll query(int o)
{
    if(a<=p[o].l&&p[o].r<=b)
        return p[o].val;
    ll ans = 0;
    if(a<=p[o].mid)
        ans = max(ans,query(o*2));
    if(b>p[o].mid)
        ans = max(ans,query(o*2+1));
    return ans;
}
int main()
{
    int q,n;
    scanf("%d%d",&n,&q);
    init(1,n,1);
    while(q--)
    {
        int t;
        scanf("%d%d%d",&t,&a,&b);
        if(t==1)
        {
            damage(1);
        }
        else
            printf("%lld\n",query(1));
    }
return 0;
}

