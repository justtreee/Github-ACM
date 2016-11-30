#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool is(LL x)
{
    for(int i=2; i*i<=x; i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    if(n==2)
        cout<<"1"<<endl;
    else if(n%2==0)
        cout<<"2"<<endl;
    else
    {
        if(is(n))
            cout<<"1"<<endl;
        else if(is(n-2))
            cout<<"2"<<endl;
        else
            cout<<"3"<<endl;
    }

    return 0;
}
