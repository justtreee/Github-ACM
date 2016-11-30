#include <stdio.h>
#include <string.h>
using namespace std;
#define M 100005
int pre[M],mark[M];//mark=friends num
int ans;
int find(int x)
{
    if(pre[x] != x)
        pre[x] = find(pre[x]);
    return pre[x];
}
int unionx(int x, int y)
{
    int fx,fy,i;
    fx = find(x);
    fy = find(y);
    if(fx != fy)
    {
        pre[fy] = fx;
        mark[fx] += mark[fy];
        if(ans< mark[fx])
            ans = mark[fx];
    }
}

int main()
{
    int n,a,b,i;

    while(~scanf("%d",&n))
    {
        ans = 0;
        if(n == 0)
        {
            printf("1\n");
            continue;
        }
        for(i=1; i<M; i++)
        {
            pre[i] = i;
            mark[i] = 1;
        }
        while(n--)
        {
            scanf("%d %d",&a,&b);
            unionx(a,b);
        }
        printf("%d\n",ans);
    }

return 0;
}
