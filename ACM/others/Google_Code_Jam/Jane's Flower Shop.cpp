#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-15;
int T,n,a[105];
double exp(double x,double p)
{
    return pow(x+1,p);
}
double f(double x)
{
    double ans=0;
    for(int i=n; i>=0; i--)
    {
        ans+=a[n-i]*exp(x,i);
    }
    return ans;
}
int main()
{
    freopen("C-large-practice.in","r",stdin);
    freopen("shop.txt","w",stdout);
    scanf("%d",&T);
    for(int cas=1; cas<=T;cas++)
    {
        scanf("%d",&n);
        for(int i=0; i<=n; i++)
        {
            scanf("%d",&a[i]);if(i==0)a[0] = -a[0];
        }
        double l=-1.0,r=1.0,mid;
        while(r-l>=eps)
        {
            mid=(l+r)/2.0;
            if(f(mid)>eps)
            {
                l = mid;
            }
            else if(f(mid)<-eps)
            {
                r=mid;
            }
            else
                break;

        }
        printf("Case #%d: %.12f\n",cas,mid);
    }

    return 0;
}


