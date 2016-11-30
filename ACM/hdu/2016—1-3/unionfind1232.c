#include <stdio.h>
int pre[1005];
int findx(int x)
{
    int r = x;
    while(pre[r] != r)
    {
        r = pre[r];
    }
    int i,t;
    i = x;
    while(pre[i] != r)
    {
        t = pre[i];
        pre[i] = r;
        i = t;
    }
    return r;

}

int unionx(int x,int y)
{
    int fx,fy;
    fx = findx(x);
    fy = findx(y);
    if(fx != fy)
        pre[fx] = fy;
}
int main()
{
    int i,a,b,ans;
    while(~scanf("%d %d",&n,&m))
    {
        ans = 0;
        for(i=1;i<=n; i++)
        {
            pre[i] = i;
        }
        for(i=1;i<=m; i++)
        {
            scanf("%d %d",&a,&b);
            unionx(a,b);
        }
        for(i=1;i<=n; i++)
        {
            if(pre[i] == i)
                ans++;
        }
        printf("%d\n",ans);

    }

return 0;
}
