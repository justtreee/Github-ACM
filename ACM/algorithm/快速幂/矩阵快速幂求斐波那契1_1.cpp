#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define Mod 1000000009
struct matrix{
    long long c[2][2];
}t;

matrix operator * (matrix a,matrix b) //MatrixMultipliction
{
    matrix c;
    int i,j,k;
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            c.c[i][j] = 0;
            for(k=0; k<2; k++)
            {
                c.c[i][j] += (a.c[i][k] * b.c[k][j])%Mod;
            }
            c.c[i][j] = c.c[i][j] % Mod;
        }

    }
    return c;
}

matrix expmod(long long n)
{
    matrix res = t;
    if(n<0)
        return res;
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
    long long n;
    while(~scanf("%lld",&n))
    {
        t.c[0][0] = 1;
        t.c[0][1] = 1;
        t.c[1][0] = 1;
        t.c[1][1] = 0;
        matrix ans = expmod(n-2);
        printf("%lld\n",ans.c[0][0]);
    }
return 0;
}



