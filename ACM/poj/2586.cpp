#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;
const int M = 1000;
const long long  INF = (0x3f3f3f3f3f3f3f3f);
typedef long long ll;
const double PI = acos(-1.0);
int main()
{
    ll s,d;
    while(cin>>s>>d)
    {
        ll ans = -INF;
        if(4*s-d<0)
        {
            ans =  10*s-2*d;
        }
        else if(3*s-2*d<0)
        {
            ans =  8*s-4*d;
        }
        else if(2*s-3*d<0)
        {
            ans =  6*s-6*d;
        }
        else if(s-4*d<0)
        {
            ans =  s*3-9*d;
        }
        if(ans>0)
            cout<<ans<<endl;
        else
            cout<<"Deficit"<<endl;
    }
return 0;
}
