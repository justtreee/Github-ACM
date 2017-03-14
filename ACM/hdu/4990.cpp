#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Mat
{
    LL m[3][3];
};
LL N,M;
Mat t1,t2;
Mat operator * (Mat a,Mat b)
{
    Mat res;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            res.m[i][j] = 0;
            for(int k=0; k<3; k++)
            {
                res.m[i][j] += (a.m[i][k]*b.m[k][j]);
            }
            res.m[i][j] %= M;
        }
    }
    return res;
}
Mat exp(Mat s,LL cnt,Mat t)
{
    Mat res=s;
    while(cnt)
    {
        if(cnt&1)
            res = res*t;
        t=t*t;
        cnt>>=1;
    }
    return res;
}
void bldt1()
{
    memset(t1.m,0,sizeof(t1.m));
    t1.m[0][0] = 2;
    t1.m[0][2] = 1;
    t1.m[1][1] = 2;
    t1.m[2][2] = 1;
}
void bldt2()
{
    memset(t2.m,0,sizeof(t2.m));
    t2.m[0][0] = 2;
    t2.m[1][1] = 2;
    t2.m[1][2] = 1;
    t2.m[2][2] = 1;
}
void test(Mat r)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<r.m[i][j]<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    Mat ini,r;

    while(~scanf("%lld%lld",&N,&M))
    {
        if(N==1)    cout<<1%M<<endl;
        else if(N==2)   cout<<2%M<<endl;
        else
        {
            memset(ini.m,0,sizeof(ini.m));
            ini.m[0][0] = 2;
            ini.m[1][0] = 1;
            ini.m[2][0] = 1;
            bldt1();
            bldt2();
            if(N%2)
            {
                Mat res;
                memset(res.m,0,sizeof(res.m));
                for(int i=0; i<3; i++)
                    res.m[i][i] = 1;
                r = t2*t1;
                r = exp(res,(N-2)/2,r);
                r = t1*r;
                r = r*ini;
                printf("%lld\n",r.m[0][0]%M);
            }
            else
            {
                Mat res;
                memset(res.m,0,sizeof(res.m));
                for(int i=0; i<3; i++)
                    res.m[i][i] = 1;
                r = t2*t1;
                r = exp(res,(N-2)/2,r);
                r = r*ini;
                printf("%lld\n",r.m[0][0]%M);
            }
        }
    }

    return 0;
}
