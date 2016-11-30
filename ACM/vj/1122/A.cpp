#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL m;
struct matrix{
    LL m[2][2];
};


matrix operator * (matrix a,matrix b)
{
    matrix c;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            c.m[i][j] = 0;
            for(int k=0; k<2; k++)
            {
                c.m[i][j] += (a.m[i][k] * b.m[k][j])%m;
            }
            c.m[i][j] = c.m[i][j] % m;

        }

    }
    return c;
}

matrix exp(LL n,matrix t)
{
    matrix res;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            if(i==j)    res.m[i][j] = 1;
            else        res.m[i][j] = 0;
        }
    }
    while(n)
    {
        if(n%2!=0)
            res = res*t;
        t = t*t;
        n>>=1;
    }
    return res;

}
int main()
{
    LL a,b,n;
    while(cin>>a>>b>>n>>m)
    {
        matrix tmp;
        tmp.m[0][0] = tmp.m[1][1] = a;
        tmp.m[0][1] = b;    tmp.m[1][0] = 1;
        matrix ans = exp(n,tmp);
        cout<<(2*ans.m[0][0])%m<<endl;

    }

    return 0;
}
