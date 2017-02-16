#include <bits/stdc++.h>
using namespace std;
int n,a[50005];
int lowbit(int x)
{
    return x&(-x);
}
void add(int i,int v)
{
    while(i<=n)
    {
        a[i]+=v;
        i+=lowbit(i);
    }
}

int sum(int x)
{
    int ans = 0;
    while(x>0)
    {
        ans+=a[x];
        x-=lowbit(x);
    }
    return ans;
}


int main()
{
    int T;
    string o;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        cout<<"Case "<<cas<<":"<<endl;
        for(int i=1; i<=n; i++)
        {int aa;
            scanf("%d",&aa);    add(i,aa);
        }
        while(1)
        {
            int p,v;
            cin>>o;
            if(o[0]=='E')
                break;
            else if(o[0]=='A')
            {
                scanf("%d%d",&p,&v);
                add(p,v);
            }
            else if(o[0]=='S')
            {
                scanf("%d%d",&p,&v);
                add(p,-v);
            }
            else
            {
                scanf("%d%d",&p,&v);
                cout<<sum(v)-sum(p-1)<<endl;
            }
        }
    }

    return 0;
}
