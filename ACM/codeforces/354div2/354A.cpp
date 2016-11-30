#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 105
#define INF (0x3f3f3f3f)
typedef long long ll;
int main()
{
    int n,a[M],b[M];
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            b[i] = a[i];
        }
        sort(b,b+n);
        int p1,p2;
        int flag1 = 0;
        int flag2 =0;

        if((a[0]==b[0]&&a[n-1]==b[n-1])||(a[n-1]==b[0]&&a[0]==b[n-1]))
        {
            printf("%d\n",n-1);
        }

        else
        {
            for(int i=0; i<n; i++)
            {
                if(a[i]==b[0]&&flag1==0)
                {
                    p1 = i+1;
                    flag1 = 1;
                }
                if(a[i]==b[n-1]&&flag2==0)
                {
                    p2 = i+1;
                    flag2 = 1;
                }
            }
            int t=min(min(n-p1,p1-1),min(n-p2,p2-1));
            printf("%d\n",n-t-1);
        }

    }
return 0;
}
