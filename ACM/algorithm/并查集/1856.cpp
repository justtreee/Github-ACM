#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int M=100005;
int father[M];
int num[M];
void init()
{
    for(int i=0; i<M; i++)
    {
        father[i] = i;
        num[i] = 1;
    }
}
int findx(int a)
{
    return father[a]==a?a:father[a]=findx(father[a]);
}
void unionx(int a,int b)
{
    int fa = findx(a);
    int fb = findx(b);
    if(fa!=fb)
    {
        father[fa] = fb;
        num[fb] +=num[fa];
    }
}
int main()
{
    int n,a,b;
    while(~scanf("%d",&n))
    {
        int cnt = 0;
        if(n==0)
        {
            cout<<"1"<<endl;    continue;
        }
        init();
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            cnt = max(cnt,max(a,b));
            unionx(a,b);
        }
        int ans = 0;
        for(int i=1; i<=cnt; i++)
        {
            ans = max(ans,num[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
