#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){return a>b;}
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T;cas++)
    {
        int n,a[100005];
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1,cmp);
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(i%3==0)  continue;
            ans+=a[i];
        }
        printf("Case #%d: %d\n",cas,ans);
    }

    return 0;
}
