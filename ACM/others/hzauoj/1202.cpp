#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL p;
LL GCD(LL a,LL b)
{
    return b==0?a:GCD(b,a%b);
}
struct Mat
{
    LL m[2][2];
};
Mat operator *(Mat a,Mat b)
{
    Mat res;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            res.m[i][j] = 0;
            for(int k=0; k<2; k++)
            {
                res.m[i][j] += a.m[i][k]*b.m[k][j]%p;
                res.m[i][j] %= p;
            }
            res.m[i][j] %= p;
        }
    }
    return res;
}
Mat exp(LL cnt)
{
    Mat res;
    memset(res.m,0,sizeof(res.m));
    for(int i=0; i<2; i++)
    {
        res.m[i][i] = 1;
    }
    Mat t;
    t.m[0][0] = 1; t.m[0][1] = 1;
    t.m[1][0] = 1; t.m[1][1] = 0;
    while(cnt>0)
    {
        if(cnt&1)
            res = res*t;
        t = t*t;
        cnt>>=1;
    }
    return res;
}

int main()
{
    LL n,m;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>p;
        LL nn = n,mm = m;
        n--;m--;
        LL gcd = GCD(nn+2,mm+2);
        //cout<<gcd<<endl;
//        Mat t1 = exp(n);
//        cout<<t1.m[0][0]<<endl;

        Mat t1 = exp(gcd-1);
        cout<<t1.m[0][0]<<endl;

    }


    return 0;
}
