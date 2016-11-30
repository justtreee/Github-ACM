#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 1000
#define INF (0x3f3f3f3f)
typedef long long ll;
int main()
{
    int ans=1;
    int n,a[1000];
    int num = 0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    if(n==1)
    {
        if(a[0]==1)
            ans = 1;
        else
            ans = 0;
    }

    else
    {
        for(int i=0; i<n; i++)
        {
            if(a[i]==0)
            {
                num++;
            }
        }
        if(num>1)
            ans = 0;
    }
    if(ans == 1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

return 0;
}
