
#include <bits/stdc++.h>
using namespace std;
int n,m,num[10000],t[20000],l,r;
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int p)
{
    while(x<=n)
    {
        t[x] += p;
        x+=lowbit(x);
    }
}
int sum(int k)
{
    int res = 0;
    while(k>0)
    {
        res+=t[k];
        k-=lowbit(k);
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int flag=1;
        cin>>n;
        memset(num,0,sizeof(num));
        memset(t,0,sizeof(t));
        for(int i=1; i<=n; i++)
        {
            cin>>num[i];
        }
        sort(num+1,num+n+1);
        for(int i=1; i<=n; i++)
        {
            add(i,num[i]);
        }
        for(int i=1; i<=n-1; i++)
        {
            if(num[i+1]>sum(i)+1)
            {
                cout<<sum(i)<<endl;
                flag = 0;
                break;
            }
        }
        if(flag)
            cout<<sum(n)<<endl;
    }
    return 0;
}
