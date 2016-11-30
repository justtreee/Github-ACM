#include <cstdio>
#include <algorithm>
using namespace std;
const long long M=100000;
const long long mod = 365*24*60*60;
struct Q
{
    long long a,b;

} que[M];
bool cmp(Q q1,Q q2)
{
    return q1.a*q2.b < q2.a*q1.b;
}
int main()
{
    int t;
    while(~scanf("%d",&t),t)
    {
        long long ans =0;
        for(int i=0; i<t; i++)
        {
            scanf("%d%d",&que[i].a,&que[i].b);
        }

        sort(que,que+t,cmp);
//        for(int i=0; i<t; i++)
//        {
//            printf("%d %d\n",que[i].a,que[i].b);
//        }
        for(int i=0; i<t; i++)
        {
            long long tmp = (que[i].a+que[i].b*ans)%mod;
            ans += tmp; ans %= mod;

        }
        printf("%lld\n",ans);
    }
    return 0;
}
