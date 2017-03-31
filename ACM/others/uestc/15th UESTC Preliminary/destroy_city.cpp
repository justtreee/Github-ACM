#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x,t;

    cin>>x;
    if(x%3==0)
        t=0;
    else
        t=1;
    cout<<(x/3)+t<<endl;

    return 0;
}
