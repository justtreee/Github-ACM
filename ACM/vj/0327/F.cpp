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
    int t,n;
    int a[M];
    double ans;
    scanf("%d",&t);
    while(t--)
    {
        double cnt = 0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(int i=n-1; i>=1; i--)
        {
            for(int j=i-1; j>=0;j--)
            {
                if(a[i]>a[j])
                    cnt++;

            }
        }
        ans = cnt/(double)(n*(n-1));
        printf("%lf\n",ans);
    }
return 0;
}
