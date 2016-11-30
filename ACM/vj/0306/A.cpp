#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define Mod  1000000007
#define N 100005
int a[N],b[N];
int main()
{
    int t,n,num = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0; i<n; i++)
        {
            scanf("%d",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        long long  ans = 1;
        int sword_max = 0;
        for(int sword_min = 0; sword_min<n; sword_min++)
        {
            while(sword_max<n && a[sword_max]<=b[sword_min])
                sword_max++;
            ans = ans * (sword_max - sword_min) %Mod;
        }
        printf("Case #%d: %lld\n",num++,ans);

    }

return 0;
}
