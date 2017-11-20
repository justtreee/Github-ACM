#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Mod = 1e9+7;
LL mpow(LL a,LL b,LL p)
{
    LL r,t;
    r = 1;
    t = a;
    while(b)
    {
        if(b%2 != 0)
            r = (r*t)%p;
        b>>=1;
        t = (t*t)%p;
    }
    return r;
}
int main()
{
    LL n,m,k;
    cin>>n>>m>>k;
    if(n%2 != m%2 && k==-1)
        cout<<0<<endl;
    else
        //cout<<mpow(2,(n-1)*(m-1),Mod)<<endl; TLE on test 17 ==> log(nm)
        cout<<mpow(mpow(2,n-1,Mod),m-1,Mod)<<endl; //logn+logm

    return 0;
}
