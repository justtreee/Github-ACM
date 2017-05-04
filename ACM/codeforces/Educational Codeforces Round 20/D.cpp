#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL len;
int k;string s;
bool bin(LL mid)
{
    LL ans = 0;
    int l = 0;
    while(l<len)
    {
        ans++;
        int r = l+mid;
        if(r>=len)
            break;
        while(s[r-1]!=' '&&s[r-1]!='-' && r>l)
            r--;
        if(l==r)
            return false;
        l = r;

    }
    if(ans<=k)
        return true;
    else
        return false;
}

int main()
{
    LL l,r;
    cin>>k;getchar();
    getline(cin,s);
    len = s.length();
    l = 0,r = len;
    while(l<r-1)
    {
        LL mid = (l+r)/2;
        if(bin(mid))
            r = mid;
        else
            l = mid;
    }
    cout<<r<<endl;

    return 0;
}
