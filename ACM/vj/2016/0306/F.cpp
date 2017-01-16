#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1002
long long a;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        long long suma = 0;
        long long sumb = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&a);
            suma |= a;
        }
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&a);
            sumb |= a;
        }
        printf("%lld\n",suma+sumb);
    }
return 0;
}
