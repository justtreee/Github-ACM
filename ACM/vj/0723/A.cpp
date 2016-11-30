#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 10005
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);
int main()
{
    int n,q,cas = 1;
    int num[M],sum[M];
    int tmp,t;
    while(~scanf("%d%d",&n,&q))
    {
        if(n==0)
            break;
        memset(sum,0,sizeof(sum));
        memset(num,0,sizeof(num));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&tmp);
            num[tmp]++;
        }
        printf("CASE# %d:\n",cas++);
        for(int i=1; i<=M; i++)
        {
            sum[i] = num[i] + sum[i-1];
        }
        for(int i=0; i<q; i++)
        {
            scanf("%d",&t);
            if(num[t])
            {
                printf("%d found at %d\n",t,sum[t-1]+1);
            }
            else
                printf("%d not found\n",t);
        }
    }

return 0;
}
