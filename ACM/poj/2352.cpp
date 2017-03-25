#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=32100;
int bit[N*2],n,x,y,ans[N*2];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int p)
{
    while(x<=N)
    {
        bit[x] += p;
        x += lowbit(x);
    }
}
int sum(int k)
{
    int res= 0;
    while(k>0)
    {
        res+=bit[k];
        k-=lowbit(k);
    }
    return res;
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(bit,0,sizeof(bit));
        memset(ans,0,sizeof(ans));
        for(int i=0 ;i<n; i++)
        {
            scanf("%d%d",&x,&y);
            x++;
            ans[sum(x)]++;
            add(x,1);
        }
        for(int i=0; i<n; i++)
        {
            printf("%d\n",ans[i]);
        }
    }

    return 0;
}
