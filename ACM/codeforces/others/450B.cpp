#include <bits/stdc++.h>
using namespace std;
const int Mod = 1e9+7;
typedef long long LL;
struct Mat
{
    LL c[2][2];
};
Mat operator * (Mat a,Mat b)
{
    Mat res;
    for(int i=0; i<2; i++)
    {
        for(int j=0 ; j<2; j++)
        {
            res.c[i][j] = 0;
            for(int k=0; k<2; k++)
            {
                res.c[i][j] = (res.c[i][j]+a.c[i][k] * b.c[k][j])%Mod;
                //BUG:a=b*c --> a=a+b*c
            }
            res.c[i][j] = res.c[i][j]%Mod;
        }
    }
    return res;
}
Mat init;
Mat expmod(Mat a,LL n)
{
    Mat res;
    res.c[0][0] = 1;
    res.c[0][1] = 0;
    res.c[1][0] = 0;
    res.c[1][1] = 1;
    Mat t=a;
    if(n<0)
        return res;
    while(n)
    {
        if(n%2!=0)
            res = res*t;
        t=t*t;
        n>>=1;
    }
    return res;
}

int main()
{
    int a,b,n;
    cin>>a>>b>>n;
    if(n==1)
    {
        if(a<0) a+=Mod;
        cout<<a<<endl;
        return 0;
    }
    else if(n==2)
    {
        if(b<0) b+=Mod;
        cout<<b<<endl;
        return 0;
    }
    else
    {
        init.c[0][0] = 1;
        init.c[0][1]=-1;
        init.c[1][0] = 1;
        init.c[1][1]=0;
        Mat r = expmod(init,n-2);
        int ans = (r.c[0][0]*b%Mod+r.c[0][1]*a%Mod)%Mod;
        if(ans<0)
            ans+=Mod;
        cout<<ans<<endl;
    }
}
