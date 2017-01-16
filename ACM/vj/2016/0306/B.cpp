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
    int n,ans,a[M],b[M];
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            b[i] = 1;
        }
        int ans = 0;
        for(int i=0;i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(a[i]>a[j] && b[i]<b[j]+1)
                    b[i] = b[j] +1;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(ans<b[i])
                ans = b[i];

        }
        printf("%d\n",ans);
    }


return 0;
}
