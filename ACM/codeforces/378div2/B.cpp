#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l[100010],r[100010];
    int lsum,rsum;
    int n,c,ans,tmp;
    while(cin>>n)
    {
        lsum=rsum=0;
        for(int i=1; i<=n; i++)
        {
            cin>>l[i]>>r[i];
            lsum+=l[i];
            rsum+=r[i];
        }
        tmp = abs(lsum-rsum);
        ans = 0;
        int ll = lsum;
        int rr = rsum;
        for(int i=1; i<=n; i++)
        {
            c = abs(l[i]-r[i]);
            if(l[i]<r[i])
            {
                ll+=c;
                rr-=c;
            }
            else
            {
                ll-=c;
                rr+=c;
            }
            if(tmp<abs(ll-rr))
            {
                tmp = abs(ll-rr);
                ans = i;
            }
            ll = lsum;
            rr = rsum;
        }
        cout<<ans<<endl;
    }

    return 0;
}
