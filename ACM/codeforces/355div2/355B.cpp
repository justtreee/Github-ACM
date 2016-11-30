#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int a[100005];
int pro,t;
int main()
{
    int n,h,k;
    while(~scanf("%d%d%d",&n,&h,&k))
    {
        pro = 0;
        t=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0; i<n; i++)
        {
            if(pro+a[i]<=h)
                pro += a[i];
            else
            {
                pro = a[i];
                t++;
            }
            int tt = pro/k;
            t+=tt;
            pro-=tt*k;
        }
        if(pro > 0)
        {
            t++;
        }
        printf("%d\n",t);
    }
    return 0;
}
