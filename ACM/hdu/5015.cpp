#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Mod=10000007;
int n,m;
struct Mat{
    LL m[15][15];
};
Mat operator * (Mat a,Mat b)
{
    Mat res;
    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=n+1; j++)
        {
            res.m[i][j]=0;
            for(int k=0; k<=n+1; k++)
            {
                if(a.m[i][k]&&b.m[k][j])
                res.m[i][j] += a.m[i][k]*b.m[k][j];
            }
            res.m[i][j] %= Mod;
        }
    }
    return res;
}
Mat t;
Mat exp(int cnt)
{
    Mat res;
    memset(res.m,0,sizeof(res.m));
    for(int i=0; i<=n+1;i++)
        res.m[i][i]=1;

    while(cnt)
    {
        if(cnt%2)
            res = res*t;
        t = t*t;
        cnt>>=1;
    }
    return res;
}
void build()
{
    memset(t.m,0,sizeof(t.m));
    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=n+1; j++)
        {
            if(j==0&&i!=n+1)
                t.m[i][j]=10;
            else if(j==n+1)
                t.m[i][j]=1;
            else if(i==n+1&&j!=n+1)
                t.m[i][j]=0;
            else if(i>=j)
                t.m[i][j]=1;
        }
    }
//    for(int i=0 ;i<=n+1; i++)
//    {
//        for(int j=0; j<=n+1; j++)
//        {
//            cout<<t.m[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        Mat a;memset(a.m,0,sizeof(a.m));
        a.m[0][0]=23;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a.m[i][0]);
        }
        a.m[n+1][0]=3;
        build();
        Mat r=exp(m);
        r = r*a;
        cout<<r.m[n][0]<<endl;
    }

    return 0;
}
