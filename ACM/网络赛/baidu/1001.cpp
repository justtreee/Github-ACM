#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007

using namespace std;

long long a[1000005];
int n,T;

int main()
{
    a[1]=1;
    a[2]=2;
    for (int i=3;i<=1000000;i++)
        a[i]=(a[i-1]+(a[i-2]*(i-1))%mod)%mod;
    scanf("%d",&T);
    int Case=1;
    while (T--)
    {
        scanf("%d",&n);
        printf("Case #%d:\n%I64d\n",Case++,a[n]);
    }
    return 0;
}
