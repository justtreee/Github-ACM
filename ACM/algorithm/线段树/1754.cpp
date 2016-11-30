#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 20000002

struct node{
    int l;
    int r;
    int mid;
    int score;
}p[M];


void init(int a,int b,int n)
{
    p[n].l = a;
    p[n].r = b;
    p[n].mid = (a+b)/2;
    p[n].score = -999;
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
        return p[n].score;
    if(a<p[n].mid)
    {
        if(b<=p[n].mid)
        {
            return query(a,b,2*n);
        }
        else
        {
            return max(query(a,p[n].mid,2*n),query(p[n].mid,b,2*n+1));
        }
    }
    else
    {
        return query(a,b,2*n+1);
    }

}

void update(int pos,int val,int n)
{
    if(val>p[n].score)
        p[n].score = val;
    if(p[n].l+1 == p[n].r)
        return ;
    if(pos < p[n].mid)
    {
        update(pos,val,2*n);
    }
    else
    {
        update(pos,val,2*n+1);
    }
}

int main()
{
    int n,m,s;
    int a,b;
    char c;
    while(~scanf("%d%d",&n,&m))
    {
        init(1,n+1,1);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&s);
            update(i,s,1);
        }
        for(int i=1; i<=m; i++)//m,n  cation!!
        {
            getchar();
            scanf("%c",&c);
            scanf("%d%d",&a,&b);
            if(c=='Q')
                printf("%d\n",query(a,b+1,1));
            else
                update(a,b,1);
        }
    }
return 0;
}
