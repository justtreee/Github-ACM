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
int main()
{
    int t;
    ll n;
    double p;
    scanf("%d",&t);
    while(t--)
    {
        cin>>n;
        p = n*log10(double(n));
        ll q = ll(p);
        p -= q;
        cout<<int(pow(10,p))<<endl;
    }
return 0;
}
