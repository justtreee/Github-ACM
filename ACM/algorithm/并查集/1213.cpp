#include <iostream>
using namespace std;
int father[1001];
void init()
{
    for(int i=0; i<1001; i++)
    {
        father[i] = i;
    }
}
int findx(int a)
{
    return father[a]==a?a:father[a]=findx(father[a]);
}
int unionx(int a,int b)
{
    int fa = findx(a);
    int fb = findx(b);
    if(fa!=fb)
    {
        father[fa] = fb;
        return 1;
    }
    else
        return 0;
}

int main()
{
    int t;
    cin>>t;
    int n,m,a,b,ans;
    while(t--)
    {
        init();
        ans=0;
        cin>>n>>m;
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            if(unionx(a,b))
                ans++;

        }
        cout<<n-ans<<endl;
    }

    return 0;
}
