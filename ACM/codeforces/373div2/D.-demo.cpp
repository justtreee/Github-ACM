
#include <bits/stdc++.h>

#define lson o<<1

#define rson o<<1|1

using namespace std;

typedef long long LL;

const int maxn=1e5+10;

const LL mod=1e9+7;

LL a[maxn];

struct matrix

{

    LL a[2][2];

};

matrix add(matrix A,matrix B)

{

    matrix C;

    for(int i=0;i<2;i++)

    {

        for(int j=0;j<2;j++)

        {

            C.a[i][j]=A.a[i][j]+B.a[i][j];

            if(C.a[i][j]>=mod)C.a[i][j]-=mod;

        }

    }

    return C;

}

matrix mul(matrix A,matrix B)

{

    matrix C;

    for(int i=0;i<2;i++)

    {

        for(int j=0;j<2;j++)

        {

            C.a[i][j]=0;

            for(int k=0;k<2;k++)

            {

                C.a[i][j]+=A.a[i][k]*B.a[k][j];

                C.a[i][j]%=mod;

            }

        }

    }

    return C;

}

matrix pow_mod(LL x)

{

    matrix s,base;

    s.a[0][0]=s.a[1][1]=1;s.a[0][1]=s.a[1][0]=0;

    base.a[0][0]=base.a[0][1]=base.a[1][0]=1;base.a[1][1]=0;

    while(x)

    {

        if(x&1)s=mul(s,base);

        base=mul(base,base);

        x>>=1;

    }

    return s;

}



struct Tree

{

    int l,r,mark;

    matrix sum,fs;

}tr[4*maxn];



inline void pushup(int o)

{

    tr[o].sum=add(tr[lson].sum,tr[rson].sum);

}

inline void pushdown(int o)

{

    if(tr[o].mark)

    {

        tr[o].mark=0;tr[lson].mark=1;tr[rson].mark=1;

        tr[lson].sum=mul(tr[lson].sum,tr[o].fs);tr[rson].sum=mul(tr[rson].sum,tr[o].fs);

        tr[lson].fs=mul(tr[lson].fs,tr[o].fs);tr[rson].fs=mul(tr[rson].fs,tr[o].fs);

        tr[o].fs.a[0][0]=tr[o].fs.a[1][1]=1;tr[o].fs.a[1][0]=tr[o].fs.a[0][1]=0;

    }

}

void build(int o,int L ,int R)

{

    tr[o].l=L;tr[o].r=R;tr[o].mark=0;

    tr[o].fs.a[0][0]=tr[o].fs.a[1][1]=1;tr[o].fs.a[0][1]=tr[o].fs.a[1][0]=0;

    if(L>=R)

    {

        tr[o].sum=pow_mod(a[L]);

        return ;

    }

    int mid=(L+R)>>1;

    build(lson,L,mid);

    build(rson,mid+1,R);

    pushup(o);

}



LL query(int o,int L,int R)

{

    //cout<<o<<" "<<L<<" "<<R<<endl;

    if(L<=tr[o].l&&R>=tr[o].r)return tr[o].sum.a[0][0];

    int mid=(tr[o].l+tr[o].r)>>1;

    pushdown(o);

    LL ans=0;

    if(L<=mid)ans+=query(lson,L,R);

    if(R>mid)ans+=query(rson,L,R);

    pushup(o);

    return ans%mod;

}



void update(int o,int L,int R,matrix num)

{

    if(L<=tr[o].l&&R>=tr[o].r)

    {

        tr[o].fs=mul(tr[o].fs,num);

        tr[o].mark=1;

        tr[o].sum=mul(tr[o].sum,num);

        return ;

    }

    pushdown(o);

    int mid=(tr[o].l+tr[o].r)>>1;

    if(L<=mid)update(lson,L,R,num);

    if(R>mid)update(rson,L,R,num);

    pushup(o);

}

int n,m;

int main()

{

    cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>a[i],a[i]--;

    build(1,1,n);

    int op,u,v;

    LL temp;

    while(m--)

    {

        cin>>op;

        if(op==1)

        {

            cin>>u>>v>>temp;

            matrix num=pow_mod(temp);

            update(1,u,v,num);

        }

        else

        {

            cin>>u>>v;

            cout<<query(1,u,v)<<endl;

        }

    }

    return 0;

}
