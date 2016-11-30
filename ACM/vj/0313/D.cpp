/*#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define ll _int64
using namespace std;
#define M 1000

int main()
{
    _int64 x1,y1,x2,y2;
    while(scanf("%I64d%I64d",&x1,&y1)!=EOF)
    {
        scanf("%I64d%I64d",&x2,&y2);
        ll num=min(abs(x1-x2),abs(y1-y2));
        ll dis=abs(abs(x1-x2)-abs(y1-y2));
        printf("%I64d\n",num+dis);
    }

return 0;
}
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x1,y1,x2,y2,ans;
int main()
{
    while(~scanf("%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2))
    {
        ll dx=abs(x1-x2),dy=abs(y1-y2);
        ans=max(dx,dy);
        printf("%I64d\n",ans);
    }
}
