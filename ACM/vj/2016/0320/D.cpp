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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        long long q;
        q = sqrt(b*b-4*a*c);
        if(q*q == b*b-4*a*c)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }

return 0;
}
