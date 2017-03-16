#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b,x,y;
LL cal(LL n)
{
    LL p = (a-1)/(b-a)+1;
    LL q = n/a;
    if(p<=q)
    {
        return p*(p-1)/2*(b-a)+p-1+n-p*a+1;
    }
    else
        return q*(q-1)/2*(b-a)+q-1+min(n,q*b)-q*a;
}
int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {
        cin>>a>>b>>x>>y;
        cout<<cal(y)-cal(x-1)<<endl;
    }

    return 0;
}

