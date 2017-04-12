#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M = 1e5+10;
const int INF = 0x3f3f3f3f;
struct Node{
    int l,r;
    LL now,mn,add;
}sg[M<<2];

void pushup(int rt)
{
    sg[rt].now = min(sg[rt*2].now,sg[rt*2+1].now);
    sg[rt].mn = min(sg[rt].mn,sg[rt].now);
}

void pushdown(int rt)
{
    if(sg[rt].add&&sg[rt].l!=sg[rt].r)
    {
        if(sg[rt].add>0)
        {
            if(sg[2*rt].add<0)
                pushdown(2*rt);
            if(sg[2*rt+1].add<0)
                pushdown(2*rt+1);
        }
        sg[2*rt].add+=sg[rt].add;
        sg[2*rt+1].add+=sg[rt].add;
        sg[2*rt].now += sg[rt].add;
        sg[2*rt+1].now += sg[rt].add;
        sg[2*rt].mn = min(sg[2*rt].mn,sg[2*rt].now);
        sg[2*rt+1].mn = min(sg[2*rt+1].mn,sg[2*rt+1].now);
        sg[rt].add = 0;
    }
}

void build(int l,int r,int rt)
{
    sg[rt].l = l;    sg[rt].r = r;
    sg[rt].mn = INF; sg[rt].now = INF;
    if(l==r)
    {   LL tmp;
        cin>>tmp;
        sg[rt].now = tmp;
        sg[rt].mn = tmp;
        return ;
    }
    int mid = l+(r-l)/2;
    build(l,mid,2*rt);
    build(mid+1,r,2*rt+1);
    pushup(rt);
}

void update(int l,int r,LL c,int rt)
{
    if(l<=sg[rt].l&&sg[rt].r<=r)
    {
        pushdown(rt);
        sg[rt].add+=c;
        sg[rt].now+=c;
        sg[rt].mn = min(sg[rt].mn,sg[rt].now);
        return ;
    }
    pushdown(rt);
    int mid = (sg[rt].l+sg[rt].r)/2;
    if(l<=mid)
        update(l,r,c,2*rt);
    if(r>mid)
        update(l,r,c,2*rt+1);
    pushup(rt);

}

LL query(int l,int r,int rt)
{
    if(l==sg[rt].l&&r==sg[rt].r)
        return sg[rt].mn;
    pushdown(rt);
    int mid = (sg[rt].l+sg[rt].r)/2;
    if(r<=mid)
        return query(l,r,2*rt);
    if(l>mid)
        return query(l,r,2*rt+1);
    return min(query(l,mid,2*rt),query(mid+1,r,2*rt+1));
}

int main()
{
    //freopen("Din.txt","r",stdin);
    int n,q;
    cin>>n;
    build(1,n,1);
    cin>>q;
    while(q--)
    {
        int l,r;LL c;
        cin>>l>>r>>c;
        update(l,r,c,1);
        cout<<query(l,r,1)<<endl;

    }

    return 0;
}
