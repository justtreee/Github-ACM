#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M=1000005;
const int INF = 1<<28;
//typedef struct sgTree{
//    int l,r;
//}sgt[M<<2];
int num[M<<2];
void pushup(int rt)
{
    num[rt] = min(num[rt*2] , num[rt*2+1]);
}

void build(int l,int r,int rt)
{
    //lazy[rt] = 0;
    if(l==r)
    {
        scanf("%d",&num[rt]);
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
}
void update(int pos,int val,int l,int r,int rt)
{
    if(l==r)
    {
        num[rt] = val;return;
    }
    int mid = (l+r)/2;
    if(pos<=mid)
        update(pos,val,l,mid,rt*2);
    else
        update(pos,val,mid+1,r,rt*2+1);
    pushup(rt);
}
LL query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
        return num[rt];
    int mid = (l+r)/2;
    //pushdown(rt,mid-l+1,r-mid);
    LL res = INF;
    if(L<=mid)
        res = min(res,query(L,R,l,mid,rt*2));
    if(R>mid)
        res =min(res,query(L,R,mid+1,r,rt*2+1));
    return res;
}
int main()
{
    int n,q;
    scanf("%d",&n);
    build(1,n,1);
    scanf("%d",&q);
    while(q--)
    {
        int op,l,r,p;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&l,&p);
            //cin>>l>>p; TLE
            update(l,p,1,n,1);
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            //cin>>l>>r; TLE
            LL ans=query(l,r,1,n,1);
            printf("%lld\n",ans);
        }
    }

    return 0;
}

