#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int M = 500005*4;
LL num[M];
int lowbit(int x)
{
    return x&(-x);
}
void add(int p,int v)
{
    while(p<=M)
    {
        num[p] += v;
        p += lowbit(p);
    }
}
LL sum(int p)
{
    LL res= 0;
    while(p>0)
    {
        res += num[p];
        p -= lowbit(p);
    }
    return res;
}

int main()
{
    int n;
    while(cin>>n&&n>0)
    {
        LL ans = 0;
        memset(num,0,sizeof(num));
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            x++;
            ans += (i-sum(x));
            add(x,1);
        }
        cout<<ans<<endl;

    }

    return 0;
}
