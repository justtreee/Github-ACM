#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;
#define M 100005
map<string,int> m;
int pre[M],sum[M];
int find(int a)
{
    if(pre[a] != a)
        pre[a] = find(pre[a]);
    return pre[a];
}

int unionx(int a, int b)
{
    int fa,fb;
    fa = find(a);
    fb = find(b);
    if(fa != fb)
    {
        pre[fb] = fa;
        sum[fa] += sum[fb];
        //friends' friends is also friends
        printf("%d\n",sum[fa]);
    }
    else
    {
        printf("%d\n",sum[fa]);
    }
}

int main()
{
    int t,i;
    char a[25], b[25];
    int n,ans;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d",&n);
            for(i=0; i<M; i++)
            {
                pre[i] = i;
                sum[i] = 1;
            }
            m.clear();
            ans =1;
            for(i=1; i<=n; i++)
            {
                scanf("%s%s",a,b);
                if(!m[a])//?
                {
                    m[a] = ans++;
                }
                if(!m[b])
                {
                    m[b] = ans++;
                }
                unionx(m[a],m[b]);
            }
        }
    }
return 0;
}
