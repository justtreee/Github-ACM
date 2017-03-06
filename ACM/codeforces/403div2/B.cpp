#include <bits/stdc++.h>
using namespace std;
const int M=6*1e5+10;
const double eps=1e-7;
typedef long long LL;
int n;double x[M],v[M];
double f(double p)
{
    double res=-1;
    for(int i=1; i<=n; i++)
    {
        double tmp = abs(p-x[i])/v[i];
        res=max(res,tmp);
    }
    return res;
}
int main()
{

    cin>>n;
    for(int i=1; i<=n;i++)
        cin>>x[i];
    for(int i=1; i<=n; i++)
        cin>>v[i];
    double l=1,r=1e9,t1,t2;
    while(l+eps<r)
    {
        t1 = (r+2*l)/3;
        t2 = (2*r+l)/3;
        if(f(t1)<=f(t2))
            r = t2;
        else
            l = t1;
    }
    printf("%.7f\n",f(l));
    return 0;
}
