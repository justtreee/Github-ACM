#include <bits/stdc++.h>
using namespace std;
const int M = 1000;
const int INF = (0x3f3f3f3f);
typedef long long ll;
const double PI = acos(-1.0);
int main()
{
    int n,a[105],b[105];
    int ca[6];
    memset(ca,0,sizeof(ca));
    scanf("%d",&n);
    for(int i=1; i<=n;i++)
    {
        scanf("%d",&a[i]);
        ca[a[i]]++;
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&b[i]);
        ca[b[i]]++;
    }
    for(int i=1; i<=5; i++)
    {
        if(ca[i]%2)
        {
            cout<<-1<<endl;return 0;
        }
        else
            ca[i]/=2;
    }
    int ans  = 0;
    for(int i=1; i<=n; i++)
    {
        ca[a[i]]--;
    }
    for(int i=1; i<=5; i++)
    {
        ans+=abs(ca[i]);
    }
    cout<<ans/2<<endl;

return 0;
}
