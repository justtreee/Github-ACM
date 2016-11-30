#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#define M 100100

using namespace std;
typedef long long ll;
int a[M];
ll PrefixSum[M];

map<ll,int> t;
int main()
{
    int n;

    while(~scanf("%d",&n))
    {
        int k =0;
        memset(PrefixSum,0,sizeof(n+5));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            PrefixSum[i] = PrefixSum[i-1] + a[i];
            t[PrefixSum[i]]++;
            k = max(k,t[PrefixSum[i]]);
        }
        printf("%d\n",n-k);

    }

    return 0;
}
