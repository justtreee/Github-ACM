#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        if(5-4*n+n*n<=0)
            cout<<"0"<<endl;
        else
            cout<<acos(-1.0)*sqrt(5-4*n+n*n)<<endl;
    }

    return 0;
}
