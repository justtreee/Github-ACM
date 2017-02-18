#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
int main()
{
    int T,n,m,k;
    cin>>T;
    while(T--)
    {
        int a[M*2];
        long long ans = 0;
        memset(a,0,sizeof(a));
        cin>>n>>m>>k;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0 ;i<n ;i++)
        {
            if(a[i]<m)
            {
                ans+=m-a[i]; int tmp = a[i];
                for(int j=i; j<i+k; j++)
                {
                    a[j] += m-tmp;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
