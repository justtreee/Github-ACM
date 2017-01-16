#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 1000
int main()
{
    long long n;
    while(~scanf("%lld",&n))
    {
        long long ans = 0;
        if(n%2)
            ans = 0;
        else
        {
            n /= 2;
            long long a,b;
            for(a=1,b=n-1; a<b; a++,b--)
            {
                ans++;
            }
        }
        printf("%lld\n",ans);
    }

return 0;
}
