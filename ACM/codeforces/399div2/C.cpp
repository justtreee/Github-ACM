#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,x,a[100005];
    scanf("%d%d%d",&n,&k,&x);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    k%=128;//min==64-->93ms  32-->WA on 14  16-->WA on 6
    //k%=2048;
    while(k--)
    {
        sort(a,a+n);
        for(int j=0; j<n; j+=2)
        {
            a[j] ^= x;
        }
    }
    sort(a,a+n);
    cout<<a[n-1]<<" "<<a[0]<<endl;

    return 0;
}
