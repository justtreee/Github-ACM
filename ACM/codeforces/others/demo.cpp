#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int x[5];
int l=0,r=4,m=l/2+r/2;
int bin(int a)
{

    if(0<=a - x[m] && a - x[m]<1)
    {
        return m;
    }
    else if(a>x[m])
    {
        l = m;
        m=l/2+r/2;
        bin(a);
    }
    else
    {
        r = m;
        m=l/2+r/2;
        bin(a);
    }
}
int main()
{
    int n,q;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x[i]);
    }
    scanf("%d",&q);
    sort(x,x+n);
    cout<<bin(q)<<endl;
    return 0;
}
