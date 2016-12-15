#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long  n,k,ans;
    cin>>n>>k;
    for(int i=1; i<=50; i++)
    {
        long long tmp = k+pow(2,i-1);
        long long m = pow(2,i);
        tmp = tmp%m;
        if(tmp==0)
        {
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
