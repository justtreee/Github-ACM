#include <iostream>
#include <cstdio>
#include <cstring>
#define M 500000
using namespace std;
struct node{
    int l;
    int r;
    int mid;
    int num;
}p[M];

void init(int a,int b,int n)
{
    p[n].l = a;
    p[n].r = b;
    p[n].mid = (a+b)/2;
    p[n].num = 0;
    if(a+1==b)
    {
        return ;
    }
    init(a,(a+b)/2,2*n);    //left son tree
    init((a+b)/2,b,2*n+1);  //right son tree

}

int query(int a,int b, int n)
{
    if(p[n].l == a && p[n].r == b)
        return p[n].num;
    if(a<p[n].mid)
    {
        if(b<=p[n].mid)
        {
            return query(a,b,2*n);
        }
        else
        {
            return query(a,p[n].mid,2*n)+query(p[n].mid,b,2*n+1);
        }
    }
    else
    {
        return query(a,b,2*n+1);
    }

}

void add(int pos,int val,int n)
{
    p[n].num += val;
    if(p[n].l + 1 == p[n].r)
        return ;
    if(pos < p[n].mid)
    {
        add(pos,val,2*n);
    }
    else
    {
        add(pos,val,2*n+1);

    }
}

void exch(int p1,int p2,int n)
{

}
int main()
{
    int t,n,op,va,i;
    scanf("%d",&t);
    while(t--)
    {
        int l,r,q;
        scanf("%d",&n);
        init(1,n+1,1);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&va);
            add(i,va,1);
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                //exchange
            }

            else
            {
                scanf("%d%d",&l,&r);
                printf("%d\n",query(l,r+1,1));
            }
        }
    }



    return 0;
}
