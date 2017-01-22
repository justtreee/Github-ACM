#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[105];
    cin>>n;
    for(int i=0; i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int t = a[n-1];int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=t-a[i];
    }
    cout<<sum<<endl;
    return 0;
}
