#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 100
int main()
{
    int c,n,a[M][M];
    while(~scanf("%d",&c))
    {
        while(c--)
        {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<=i; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<=i; j++)
            {
                a[i-1][j] += max(a[i][j],a[i][j+1]);
            }
        }
        printf("%d\n",a[0][0]);
        }
    }
return 0;
}
