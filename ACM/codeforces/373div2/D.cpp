#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define lson o<<1
#define rson o<<1|1
using namespace std;
const long long  Mod = 1e9+7;
const long long M = 1e5+10;
long long a[M];
struct matrix
{
    long long c[2][2];
}q;

matrix operator * (matrix a,matrix b) //MatrixMultipliction
{
    matrix c;
    int i,j,k;
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            c.c[i][j] = 0;
            for(k=0; k<2; k++)
            {
                c.c[i][j] += (a.c[i][k] * b.c[k][j]);
                c.c[i][j] = c.c[i][j] % Mod;
            }

        }

    }
    return c;
}

matrix expmod(long long n)
{
    q.c[0][0] = 1;
    q.c[0][1] = 1;
    q.c[1][0] = 1;
    q.c[1][1] = 0;
    matrix res = q;
    res.c[1][1] = 1;
    res.c[0][1] = res.c[1][0] = 0;
    while(n)
    {
        if(n%2!=0)
            res = res*q;
        q = q*q;
        n>>=1;
    }
    return res;
}
matrix add(matrix a,matrix b)
{
    matrix c;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            c.c[i][j] = a.c[i][j]+b.c[i][j];
            if(c.c[i][j]>=Mod)
                c.c[i][j] -= Mod;
        }
    }
}


struct Tree{
    int l,r,mark;
    matrix sum,fs;
}t[4*M];
void pushup(int o)
{
    t[o].sum = add(t[lson].sum,t[rson].sum);
}
void pushdn(int o)
{
    if(t[o].mark)
    {
        t[o].mark = 0;
        t[lson].mark = 1;
        t[rson].mark = 1;
        t[lson].sum = t[lson].sum*t[o].fs;
        t[rson].sum = t[rson].sum*t[o].fs;
        t[lson].fs = t[lson].fs*t[o].fs;
        t[rson].fs = t[rson].fs*t[o].fs;
        t[o].fs.c[0][0] = t[o].fs.c[1][1] = 1;
        t[o].fs.c[1][0] = t[o].fs.c[0][1] = 0;
    }
}
void build(int o,int L,int R)
{
    t[o].l = L; t[o].r = R; t[o].mark = 0;
    t[o].fs.c[0][0] = t[o].fs.c[1][1] = 1;
    t[o].fs.c[0][1] = t[o].fs.c[1][0] = 0;
    if(L>=R)
    {
        t[o].sum = expmod(a[L]);    return ;
    }
    int mid = (L+R)>>1;
    build(lson,L,mid);
    build(rson,mid+1,R);
    pushup(o);
}
long long query(int o,int L,int R)
{
    if(L<=t[o].l && R>=t[o].r)  return t[o].sum.c[0][0];
    int mid = (t[o].l+t[o].r)>>1;
    pushdn(o);
    long long ans = 0;
    if(L<=mid)  ans+=query(lson,L,R);
    if(R>mid)   ans+=query(rson,L,R);
    pushup(o);
    return ans%Mod;

}
void update(int o,int L,int R,matrix num)
{
    if(L<=t[o].l && R>=t[o].r)
    {
        t[o].fs = t[o].fs*num;
        t[o].mark = 1;
        t[o].sum = t[o].sum*num;
        return ;
    }
    pushdn(o);
    int mid = (t[o].l+t[o].r)>>1;
    if(L<=mid)  update(lson,L,R,num);
    if(R>mid)   update(rson,L,R,num);
    pushup(o);
}
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i],a[i]--;
    }
    build(1,1,n);
    int op,u,v;
    long long tmp;
    while(m--)
    {
        cin>>op;
        if(op == 1)
        {
            cin>>u>>v>>tmp;
            matrix num = expmod(tmp);
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

