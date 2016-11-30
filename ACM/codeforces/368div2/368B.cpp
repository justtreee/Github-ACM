#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n,m,k,u[100005],v[100005],l[100005],a[100005];
    scanf("%d%d%d",&n,&m,&k);
    memset(a,0,sizeof(a));
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&l[i]);
    }
    for(int i=0; i<k; i++)
    {
        int x;
        scanf("%d",&x);
        a[x] = 1;
    }
    int ans = 0x3f3f3f3f;
    for(int i=0; i<m; i++)
    {
        if(a[u[i]]+a[v[i]]==1)
            ans = min(ans,l[i]);
    }
    if(ans!=0x3f3f3f3f)
        printf("%d\n",ans);
    else
        printf("-1\n");


    return 0;
}
