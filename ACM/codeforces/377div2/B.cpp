#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 505
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);
int main()
{
    int n,k,a[M],ans=0;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(i>0)
        {
            int tmp = k-(a[i]+a[i-1]);
            if(tmp>0)
            {
                ans+=tmp;
                a[i]+=tmp;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }


    return 0;
}
