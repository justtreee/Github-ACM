#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100005],suf[100005];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(suf,0,sizeof(suf));
        int flag = 1;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
        }
        sort(a,a+n);
        suf[0] = a[0];
        for(int i=1; i<n; i++)
        {
            suf[i] = suf[i-1] + a[i];
            if(a[i]>suf[i-1]+1)
            {
                printf("%d\n",suf[i-1]);
                flag = 0;
            }

        }
        if(flag)
        {
            printf("%d\n",suf[n-1]);
        }

    }
    return 0;
}
