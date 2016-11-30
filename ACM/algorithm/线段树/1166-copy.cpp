#include <stdio.h>
#include <string.h>
#define M  500002
struct node
{
    int l;
    int r;
    int mid;
    int num;
} p[M];
void init(int a,int b,int n)
{
    p[n].l = a;
    p[n].r = b;
    p[n].mid = (a+b)/2;
    p[n].num = 0;
    if(a + 1 == b)
    {
        return ;
    }
    init(a,(a+b)/2,2*n);
    init((a+b)/2,b,2*n+1);
}
void add(int pos,int value,int n)
{
    p[n].num += value;
    if(p[n].l + 1 == p[n].r)
        return ;
    if(pos < p[n].mid)
    {
        add(pos,value,2*n);
    }
    else
    {
        add(pos,value,2*n + 1);
    }
}
void sub(int pos,int value,int n)
{
    p[n].num -= value;
    if(p[n].l + 1 == p[n].r)
        return ;
    if(pos < p[n].mid)
        sub(pos,value,2*n);
    else
        sub(pos,value,2*n + 1);
}
int query(int a,int b,int n)
{
    if(p[n].l == a && p[n].r == b)
        return p[n].num;
    if(a < p[n].mid )
    {
        if(b <= p[n].mid )
        {
            return query(a,b,2*n);
        }
        else
        {
            return query(a,p[n].mid,2*n) + query(p[n].mid,b,2*n + 1);
        }
    }
    else
        return query(a,b,2*n+1);
}
int main()
{
    int t;
    int N,i,va;
    char c[10];
    int ax,ay;
    int times = 0;
    scanf("%d",&t);
    while(t--)
    {
        memset(c,0,sizeof(c));
        scanf("%d",&N);
        init(1,N+1,1);
        for(i = 1; i <= N; i++)
        {
            scanf("%d",&va);
            add(i,va,1);
        }
        printf("Case %d:\n",++times);
        while(1)
        {
            scanf("%s",c);
            if( !strcmp(c,"End"))
            {
                break;
            }
            scanf("%d%d",&ax,&ay);
            if( strcmp(c,"Query") == 0)
            {
                printf ("%d\n",query(ax,ay+1,1));
            }
            else if(strcmp(c,"Add") == 0)
            {
                add(ax,ay,1);
            }
            else if(strcmp(c,"Sub") == 0)
            {
                sub(ax,ay,1);
            }

        }
    }
    return 0;
}
