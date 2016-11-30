#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M 100000
int main()
{
    int t,n,a[M];
    int strt,end,pos,max,ans;
    int cnt = 1;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        max = ans = a[0];
        pos = strt = end = 0;
        for(int i=1; i<n; i++)
        {
            if(max + a[i] < a[i])
            {
                max = a[i];
                pos = i;
            }
            else
            {
                max += a[i];

            }
            if(max > ans)
            {
                ans = max;
                strt = pos;
                end = i;
            }
        }
        printf("Case %d:\n%d %d %d\n",cnt++,ans,strt+1,end+1);
        if(t)
            printf("\n");
    }
return 0;
}
