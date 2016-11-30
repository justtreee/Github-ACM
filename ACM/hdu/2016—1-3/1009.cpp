#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 1005

struct ware{
    double j,f,p;
};

ware w[M];
bool cmp(ware a,ware b)
{
    return a.p > b.p;
}
void init()
{
    int i;
    for(i=0; i<M;i++)
    {
        w[i].f = w[i].j = w[i].p = 0;
    }
}
int main()
{
    int n;
    double m,ans;
    while(~scanf("%lf %d",&m,&n))
    {
        init();
        if(m==-1 && n==-1)
            break;
        int i;
        for(i=0; i<n; i++)
        {
            scanf("%lf %lf",&w[i].j,&w[i].f);
            w[i].p = w[i].j/w[i].f;

        }
        sort(w,w+n,cmp);
        ans = 0;
        for(i=0; i<n && m; i++)
        {
            if(m>=w[i].f)
            {
                m -= w[i].f;
                ans += w[i].j;
            }
            else
            {
                ans += m /w[i].f* w[i].j;
                m = 0;
            }

        }
        printf("%.3f\n",ans);

    }
return 0;
}
