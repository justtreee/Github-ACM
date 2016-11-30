#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL Mod = 2147493647;
struct Matrix{
    LL m[7][7];
    void init()
    {
        m[0][0] = 1,m[0][1] = 2,m[0][2] = 1,m[0][3] = 4,m[0][4] = 6,m[0][5] = 4,m[0][6] = 1;
         m[1][0] = 1,m[1][1] = 0,m[1][2] = 0,m[1][3] = 0,m[1][4] = 0,m[1][5] = 0,m[1][6] = 0;
         m[2][0] = 0,m[2][1] = 0,m[2][2] = 1,m[2][3] = 4,m[2][4] = 6,m[2][5] = 4,m[2][6] = 1;
         m[3][0] = 0,m[3][1] = 0,m[3][2] = 0,m[3][3] = 1,m[3][4] = 3,m[3][5] = 3,m[3][6] = 1;
         m[4][0] = 0,m[4][1] = 0,m[4][2] = 0,m[4][3] = 0,m[4][4] = 1,m[4][5] = 2,m[4][6] = 1;
         m[5][0] = 0,m[5][1] = 0,m[5][2] = 0,m[5][3] = 0,m[5][4] = 0,m[5][5] = 1,m[5][6] = 1;
         m[6][0] = 0,m[6][1] = 0,m[6][2] = 0,m[6][3] = 0,m[6][4] = 0,m[6][5] = 0,m[6][6] = 1;

    }
}M;

Matrix operator *(Matrix a,Matrix b)
{
    Matrix c;
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<7; j++)
        {
            c.m[i][j] = 0;
            for(int k=0; k<7; k++)
            {
                c.m[i][j] +=(a.m[i][k]*b.m[k][j])%Mod;
            }
            c.m[i][j]%=Mod;
        }
    }
    return c;
}
Matrix operator ^(Matrix t,int k)
{
    Matrix ans;
    ans.init();

    while(k)
    {
        if(k%2!=0)
           ans = ans*t;
        t=t*t;
        k>>=1;
    }
    return ans;
}

int main()
{
    int T;
    LL n,a,b;
    cin>>T;
    while(T--)
    {
        cin>>n>>a>>b;
        if(n==1)
        {
            cout<<a%Mod<<endl;
            continue;
        }
        if(n==2)
        {
            cout<<b%Mod<<endl;
            continue;
        }
        Matrix ans,t;
        t.init();
        memset(ans.m,0,sizeof(ans.m));
        ans.m[0][0] = b;ans.m[1][0] = a;ans.m[2][0] = 16;
        ans.m[3][0] = 8;ans.m[4][0] = 4;ans.m[5][0] = 2;
        ans.m[6][0] = 1;
        ans = (t^(n-3)) * ans;
        cout<<ans.m[0][0]<<endl;

    }
    return 0;
}


