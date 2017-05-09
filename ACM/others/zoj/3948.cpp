#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M = 100000;
const int INF = 0x3f3f3f3f;

int main()
{
    int T,a,b,x,y;
    cin>>T;
    while(T--)
    {
        cin>>x>>y>>a>>b;
        int cnt = 0;
        int ans = 0;
        while((a>=x||b>=y))
        {
            if(a>=x)
            {
                cnt += a/x;
                a %= x;
            }
            if(b>=y)
            {
                cnt += b/y;
                b %= y;
            }
            a += cnt;
            b += cnt;
            ans += cnt;
            cnt = 0;
            if(ans>10000)
                break;
            //cout<<"a: "<<a<<endl<<"b: "<<b<<endl;

        }
        //cout<<"ff"<<flag<<endl;
        if(ans<=10000)
        cout<<ans<<endl;
        else
            puts("INF");
    }

    return 0;
}
