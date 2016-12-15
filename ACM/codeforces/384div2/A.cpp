#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b; char s[100005];
    cin>>n>>a>>b;
    a--;    b--;
    cin>>s;
    if(s[a]==s[b])  cout<<0<<endl;
    else
    {
        cout<<1<<endl;
    }
    return 0;
}
