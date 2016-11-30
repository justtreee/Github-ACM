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
    int t,n,sum,a;
    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&a);
            a++;
            sum += a;
        }
        printf("%d\n",sum);
    }

return 0;
}

