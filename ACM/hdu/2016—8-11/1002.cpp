#include <iostream>
using namespace std;
int main()
{
    int T,x,k,t;
    cin>>T;
    while(T--)
    {
        cin>>x>>k>>t;
        int ans =0;
        int tmp = x-x%k;
        ans+=tmp/k-1;
        tmp = x%k;

        cout<<ans<<endl;
    }

    return 0;
}
