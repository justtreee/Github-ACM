#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 2005
int pre[M],treNUM[M] = {0};

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
    if(fa != fb)
        pre[fb] = fa;
}
int main()
{
    int n,i,a,ans;
    int j;
    while(~scanf("%d",&n))
    {
        ans = 0;
        for(i = 0;i<M; i++)
        {
            pre[i] = i;
        }
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a);
            if(a == -1)
            {

                for(j=1;j<M; j++)
                {
                    treNUM[j] = i;
                }
            }
            else
            {
                unionx(a,i);
            }
        }
        for(i=1;i<j;i++)
        {
            int k;
            for(k=1;k<M;k++)
            {
                if(pre[k] == treNUM[i])
                {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);

    }
return 0;
}
