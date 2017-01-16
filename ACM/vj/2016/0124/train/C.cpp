#include <stdio.h>
using namespace std;
#define M 1005
int pre[M],ans;
int find(int a)
{
    if(pre[a]!= a)
        pre[a] = find(pre[a]);
    return pre[a];
}
int unionx(int a,int b)
{
    int fa,fb;
    fa = find(a);
    fb = find(b);
    if(fa == fb)
        ans++;
    else
        pre[fb] = fa;
}
int main()
{
    int n,m,a,b;
    int i,j;
    while(~scanf("%d %d",&n,&m))
    {
        ans = 0;
        for(i =0; i<M;i++)
        {
            pre[i] = i;
        }
        while(m--)
        {
            scanf("%d%d",&a,&b);
            unionx(a,b);
        }
        printf("%d\n",ans);
    }
return 0;
}
