#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Mod = 1e9+7;
LL exp(LL a,LL b,LL p)
{
    LL r,t;
    r=1;
    t=a;
    while(b)
    {
        if(b%2!=0)
            r=(r*t)%p;
        b>>=1;
        t=(t*t)%p;
    }
    return r;

}
int main()
{
    LL n,k;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>k;
        if(n<k)     cout<<"0"<<endl;
        else if(n==k)    cout<<"1"<<endl;
        else if(n-k==1)  cout<<"2"<<endl;
        else{
            cout<<((n-k+3)%Mod)*(exp(2,n-k-2,Mod))%Mod<<endl;
        }
    }

    return 0;
}
