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
    ll a[3],ans=0,mm;
    cin>>a[0]>>a[1]>>a[2];
    mm = max(max(a[0],a[1]),a[2]);
    for(int i=0; i<3; i++)
    {
        if(a[i]<mm)
            ans+=mm-1-a[i];
    }
    cout<<ans<<endl;

return 0;
}
