#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    if(n<=2){
        cout<<"-1"<<endl;
        return 0;
    }
    if(n%2)
    {
        long long a=(n-1)/2;
        //cout<<1<<endl<<2<<endl;
        cout<<2*a*a+2*a<<" "<<2*a*a+2*a+1<<endl;
        return 0;
    }
    else
    {
        long long a=n/2;
        cout<<a*a-1<<" "<<a*a+1<<endl;
    }
}
