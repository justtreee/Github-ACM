#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    ll n;
    cin>>t;
    for(int cas = 1;cas<=t; cas++)
    {
        cin>>n;
        cout<<"Case #"<<cas<<": "<<(2+n)*(n-1)/2<<endl;
    }

    return 0;
}
