#include <bits/stdc++.h>
using namespace std;
const int M=1005;
const int Mod = 1e9+7;
typedef long long LL;
LL bit[M][M];
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int y,int v)
{
    for(int i=x; i<M; i+=lowbit(i))
    {
        for(int j=y; j<M; j+=lowbit(j))
        {
            bit[i][j] += v;
        }
    }
}
LL query(int x,int y)
{
    LL res=0;
    for(int i=x;i>=1; i-=lowbit(i))
    {
        for(int j=y; j>=1; j-=lowbit(j))
        {
            res += bit[i][j]%Mod;
            res %= Mod;
        }
    }
    res %= Mod;
    return res;
}
LL sum(int x1,int y1,int x2,int y2)
{
    return query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1);
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        char op[5];
        scanf("%s",op);
        if(op[0]=='A')
        {
            int x,y,v;
            cin>>x>>y>>v;
            x++,y++;
            update(x,y,v);
        }
        else
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            x1++,x2++,y1++,y2++;
            LL ans = sum(x1,y1,x2,y2);
            if(ans<0)   ans+=Mod;
            ans %= Mod;
            cout<<ans<<endl;
        }
    }

    return 0;
}
