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
int main()
{
    ll n,a[505][505];
    int r,c;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
            {
                r = i;
                c = j;
            }
        }
    }
    if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    ll sum = 0;


    int row = 1;
    if(r==1)
        row = 2;
    for(int j=1; j<=n; j++)
    {
        sum += a[row][j];
    }
    ll tmp = sum;
    for(int j=1; j<=n; j++)
    {
        if(j!=c)
            tmp -= a[r][j];
    }
    int flag = 1;
    if(tmp<1)
        flag = 0;
    a[r][c] = tmp;

    for(int i=1; i<=n&&flag; i++)
    {
        ll rsum = 0;
        ll csum = 0;
        for(int j=1; j<=n&&flag; j++)
        {
            rsum += a[i][j];
            csum += a[j][i];
        }
        if(rsum != sum||csum!=sum)
        {
            flag = 0;
            break;
        }
    }
    ll xsum1 = 0;
    ll xsum2 = 0;
    for(int i=1; i<=n && flag; i++)
    {
        xsum1 += a[i][i];
    }
    for(int i=1; i<=n; i++)
    {
        xsum2 += a[i][n-i+1];
    }
    if(xsum1!=sum||xsum2!=sum)
        flag = 0;
    if(flag)
        cout<<a[r][c]<<endl;
    else
        cout<<"-1"<<endl;

return 0;
}
