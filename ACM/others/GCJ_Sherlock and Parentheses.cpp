#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("C-large-practice.in","r",stdin);
    freopen("out.out","w",stdout);
    int T;
    cin>>T;
    for(int cas=1; cas<=T;cas++)
    {int a,b;
        cin>>a>>b;
        long long n = min(a,b);
        cout<<"Case #"<<cas<<": "<<(n+1)*n/2<<endl;
    }

    return 0;
}
