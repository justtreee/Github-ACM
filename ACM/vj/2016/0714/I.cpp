#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 100001
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);

int n,s[M],c;

int bin(int mid)
{
    int i,pos,sum;
    pos = 1;
    for(int i=1; i<c; i++)
    {
        sum = 0;
        while(pos < n && sum <mid)
        {
            sum += (s[pos] - s[pos-1]);
            pos++;
        }
        if(sum < mid)
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&c);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&s[i]);
        }
        sort(s,s+n);
        int l = 0;
        int r = (s[n-1]-s[0])/(c-1);
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(bin(mid))
                l = mid+1;
            else
                r = mid-1;

        }
        printf("%d\n",r);
    }
    return 0;
}
