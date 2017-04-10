#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M= 1000005;
LL num[M],n;
int lowbit(int x)
{
    return x&(-x);
}
void update(int p,int k)
{
    while(p<=M)
    {
        num[p] += k;
        p += lowbit(p);
    }
}
LL sum(int p)
{
    LL res = 0;
    while(p>0)
    {
        res += num[p];
        p-=lowbit(p);
    }
    return res;
}
int main()
{
    LL ans=0;int x;
    scanf("%d",&n);
    memset(num,0,sizeof(num));
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        ans += i-sum(x);
        update(x,1);
    }
    printf("%lld\n",ans);
    return 0;
}
