#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int Mod = 1000000000;
typedef long long LL;

struct Mat
{
    LL m[2][2];
};
Mat operator * (Mat a,Mat b)
{
    Mat res;
    memset(res.m,0,sizeof(res.m));
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                res.m[i][j] += a.m[i][k]*b.m[k][j];
                res.m[i][j]%=Mod;
            }
            res.m[i][j]%=Mod;
        }
    }
    return res;
}

Mat exp(int cnt)
{
    Mat res;
    for(int i=0 ; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            if(i==j)    res.m[i][j]=1;
            else        res.m[i][j]=0;
        }
    }
    Mat a;
    a.m[0][0]=1;
    a.m[0][1]=1;
    a.m[1][0]=1;
    a.m[1][1]=0;
    while(cnt>0)
    {
        if(cnt&1)
        {
            res = res*a;
        }
        cnt>>=1;
        a = a*a;
    }
    return res;
}

int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        LL ans=0;
        if(a==0&&b==0)
            break;
//        for(int i=a; i<=b; i++)
//        {
//            Mat ans1;
//            ans1 = exp(i);
//            //cout<<ans1.m[0][0]<<endl;
//            ans+=ans1.m[0][0];
//            ans%=Mod;
//        }
        Mat t1,t2;
        t1 = exp(b+2);t2 = exp(a+1);
        LL sb = t1.m[0][0]-2;
        LL sa = t2.m[0][0]-2;
        ans = (sb-sa)%Mod;
        if(ans<0)
            ans = (ans+Mod)%Mod;
        cout<<ans<<endl;
    }

    return 0;
}
