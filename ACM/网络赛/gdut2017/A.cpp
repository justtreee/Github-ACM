#include <iostream>
using namespace std;
int main()
{
    int T,a,b,c;
    cin>>T;
    while(T--)
    {
        cin>>a>>b>>c;
        cout<<b-(c-2*a)/4<<endl;
    }

    return 0;
}
