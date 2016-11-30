#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,c,t[100005];
    cin>>n>>c;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&t[i]);

    }
    int ans=1;
    for(int i=2; i<=n ;i++)
    {
        if(t[i]-t[i-1]<=c)
            ans++;
        else
            ans = 1;
    }
    cout<<ans<<endl;
    return 0;
}
