#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 100005
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);
int main()
{
    int n,a[M],b[M];
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(i>1)
        {
            b[i-1] = a[i]+a[i-1];
        }
        if(i==n)
            b[i]=a[i];
    }
    for(int i=1; i<=n; i++)
    {
        if(i==1)
            cout<<b[i];
        else
            cout<<" "<<b[i];
    }
return 0;
}
