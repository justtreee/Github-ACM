#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1005
struct work{
    int dl;
    int rdc;
}s[M];
int mark[M];
int  cmp(const work a,const work b)
{
    if(a.rdc>b.rdc)//shengxu
        return 1;
    else if(a.rdc==b.rdc && a.dl<b.dl)
        return 1;
    else
        return 0;
}
int main()
{
    int t,n,a[M],b[M];
    scanf("%d",&t);
    while(t--)
    {
        memset(mark,0,sizeof(mark));
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&s[i].dl);
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&s[i].rdc);
        }
        sort(s+1,s+1+n,cmp);
        int ans=0;
        int i,j;
        for(i=1; i<=n; i++)
        {
            for(j=s[i].dl; j>=1; j--)
            {
                if(!mark[j])
                {
                    mark[j] = 1;
                    break;
                }
            }
            if(0==j)
            {
                ans += s[i].rdc;
            }
        }


        printf("%d\n",ans);
    }
return 0;
}
