#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k,a,b,ans;
    while(cin>>k>>a>>b)
    {
        int aa = a/k,bb=b/k;
        a%=k;   b%=k;
        if((a>0&&bb==0)||(b>0&&aa==0))
            cout<<-1<<endl;
        else
            cout<<aa+bb<<endl;
    }

    return 0;
}
