#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 100000
int a[M];
int main()
{
    int ans,max,i,j,k=0,t,n;
    int start,end,pos;
    scanf("%d",&t);
    while(t--)
    {
        k++;
        pos = start = end = 0;

        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        max = ans = a[0];
        for(i=1; i<n; i++)
        {
            if(max+a[i] < a[i])
            {
                max = a[i];
                pos = i;
            }
            else
            {
                max = max + a[i];
            }
            if(max > ans)
            {
                ans = max;
                start = pos;
                end = i;
            }
        }
        printf("Case %d:\n%d %d %d\n",k,ans,start+1,end +1);
        if(t)
            printf("\n");

    }

return 0;
}
