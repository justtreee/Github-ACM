#include <bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int main()
{
    int n,a[M];
    cin>>n;int ans = 0;
    for(int i=0 ;i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i =0; i<n; i++)
    {
        if(a[i]>a[0]&&a[i]<a[n-1])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
