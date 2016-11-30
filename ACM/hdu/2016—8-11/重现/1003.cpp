#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t,a,b,c,d;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        cin>>a>>b;


        cout<<"Case #"<<cas<<":"<<endl;
        if(a==b)
        {
            cout<<"1"<<endl<<a<<" "<<b<<endl;
        }
        else
        {
            if(a<b)
            {
                cout<<"2"<<endl<<a<<" "<<b<<endl;
                cout<<b<<" "<<a<<endl;
            }
            else
            {
                cout<<"2"<<endl<<b<<" "<<a<<endl;
            cout<<a<<" "<<b<<endl;
            }
        }

    }

    return 0;
}

