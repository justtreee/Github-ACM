//============unfinished===========

#include <bits/stdc++.h>
using namespace std;
const int Mod = 112233;
typedef long long LL;
struct matrix{
    int m[14][14];
};
matrix operator * (matrix a,matrix b)
{
    matrix c;
    for(int i=0; i<14; i++)
    {
        for(int j=0; j<14; j++)
        {
            c.m[i][j] = 0;
            for(int k=0; k<14; k++)
            {
                c.m[i][j] += a.m[i][k] * b.m[k][j]%Mod;
            }
            c.m[i][j] = c.m[i][j]%Mod;
        }
    }
}
matrix init(matrix a)
{

}

matrix exp(LL n,matrix t)
{
    matrix res;
    memset(res.m,0,sizeof(res.m));
    while(n)
    {
        if(n%2!=0)
            res = res*t;
        t=t*t;
        n>>=1;
    }
    return res;
}
