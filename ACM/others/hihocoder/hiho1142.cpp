#include <bits/stdc++.h>
using namespace std;
const double Eps = 0.0001;
const double M = 1000;
double a,b,c,p,q;
double f(double x)
{
    return sqrt((p-x)*(p-x)+(q-(a*x*x+b*x+c))*(q-(a*x*x+b*x+c)));
}
double dis(double x1,double x2)
{
    double y1 = a*x1*x1+b*x1+c;
    double y2 = a*x2*x2+b*x2+c;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    //freopen("in.txt","r",stdin);
    cin>>a>>b>>c>>p>>q;
    double l=-M,r=M;
    //====trick====
    double key = -b/(2*a);
    if(key < p)
    {
        l = key+Eps;
        r = M;
    }
    else
    {
        l = -M;
        r = key - Eps;
    }
    //====trick====
    while(dis(l,r)>Eps)
    {
        double midl = l+(r-l)/3;
        double midr = r-(r-l)/3;
        if(f(midl)<f(midr))
            r = midr;
        else
            l = midl;
        //cout<<l<<" "<<r<<endl;
    }
    double ans = f((l+r)/2);
    printf("%.3lf\n",ans);


    return 0;
}
