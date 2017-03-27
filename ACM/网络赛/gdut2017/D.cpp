#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
int main()
{
    int T;
    LL a,b,c,ans;
    scanf("%d",&T);
    while(T--)
    {
        ans = 0;
        scanf("%lld%lld%lld",&a,&b,&c);
        LL cnt=a/30;
        ans = cnt*c+a*b;
        cout<<ans<<endl;
    }

    return 0;
}
