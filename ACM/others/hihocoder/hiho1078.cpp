#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M=100005;
//typedef struct sgTree{
//    int l,r;
//}sgt[M<<2];
int sum[M<<2], lazy[M<<2];
void pushup(int rt)
{
    sum[rt] = sum[rt*2] + sum[rt*2+1];
}

void pushdown(int rt,int l,int r)
{
    if(lazy[rt])
    {
        sum[rt*2] = l*lazy[rt];
        sum[rt*2+1] = r*lazy[rt];
        lazy[rt*2] = lazy[rt];
        lazy[rt*2+1] = lazy[rt];
        lazy[rt] = 0;
    }
}
void build(int l,int r,int rt)
{
    lazy[rt] = 0;
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
    return ;
}
void update(int L,int R,int prc,int l,int r,int rt)
{
    if(L<=l && R>=r)
    {
        sum[rt] = (r-l+1)*prc;
        lazy[rt] = prc;
        return ;
    }
    int mid = (l+r)/2;
    pushdown(rt,mid-l+1,r-mid);
    if(L<=mid)
        update(L,R,prc,l,mid,rt*2);
    if(R>mid)
        update(L,R,prc,mid+1,r,rt*2+1);
    pushup(rt);
    return;
}
LL query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
        return sum[rt];
    int mid = (l+r)/2;
    pushdown(rt,mid-l+1,r-mid);
    int res = 0;
    if(L<=mid)
        res+=query(L,R,l,mid,rt*2);
    if(R>mid)
        res+=query(L,R,mid+1,r,rt*2+1);
    return res;
}
int main()
{
    int n,q;
    cin>>n;
    build(1,n,1);
    cin>>q;
    while(q--)
    {
        int op,l,r,p;
        cin>>op;
        if(op==1)
        {
            cin>>l>>r>>p;
            update(l,r,p,1,n,1);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            LL ans=query(l,r,1,n,1);
            cout<<ans<<endl;
        }
    }

    return 0;
}
