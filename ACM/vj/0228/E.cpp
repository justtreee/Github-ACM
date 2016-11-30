#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 105
struct show{
    int s;
    int e;
}pre[M];
bool cmp(show a,show b)
{
    return a.e < b.e;
}
int main()
{
    int n,ans;
    while(~scanf("%d",&n),n)
    {
        memset(pre,0,sizeof(pre));
        ans = 1;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&pre[i].s,&pre[i].e);
        }
        sort(pre,pre+n,cmp);
        int temp = pre[0].e;
        for(int i=1; i<n; i++)
        {
            if(pre[i].s >= temp)
            {
                ans++;
                temp = pre[i].e;
            }
        }
        printf("%d\n",ans);

    }
return 0;
}
