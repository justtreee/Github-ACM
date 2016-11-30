#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 1000
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);
struct point{
    int x,y,r;
};
double s(point a)
{
    return PI*a.r*a.r;
}

double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double cal(point a,point b)
{
    point ta = a;
    point tb = b;
    if(ta.r<tb.r)
        swap(ta,tb);
    double area = 0;
    double d = dis(ta,tb);
    if(d>ta.r-tb.r && d<ta.r+tb.r)
    {
        double cos1 = (ta.r*ta.r+d*d-tb.r*tb.r)/(2*ta.r*d);
        double cos2 = (tb.r*tb.r+d*d-ta.r*ta.r)/(2*tb.r*d);
        double t1 = 2 *acos(cos1);
        double t2 = 2 *acos(cos2);
        double s1 = ta.r*ta.r*sin(t1)/2.0;
        double s2 = tb.r*tb.r*sin(t2)/2.0;
        double s3 = (t1/2)*ta.r*ta.r;
        double s4 = (t2/2)*tb.r*tb.r;
        area = s3+s4-s1-s2;
    }
    else if(d<=ta.r-tb.r)
        area = s(tb);
    return area;
}
int main()
{
    int t,cas = 1;
    double r,R,a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf",&r,&R);
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        point p[4];
        p[0].x=a,p[0].y=b,p[0].r=r;
        p[1].x=a,p[1].y=b,p[1].r=R;
        p[2].x=c,p[2].y=d,p[2].r=r;
        p[3].x=c,p[3].y=d,p[3].r=R;
        double s1 = cal(p[0],p[2]);
        double s2 = cal(p[0],p[3]);
        double s3 = cal(p[1],p[2]);
        double s4 = cal(p[1],p[3]);
        printf("Case #%d: %.6lf\n",cas++,s4+s1-s2-s3);

    }
return 0;
}
