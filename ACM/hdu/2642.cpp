#include <bits/stdc++.h>
using namespace std;
const int M=1005;
int a[M][M],vis[M][M];
int lowbit(int x)
{
    return x&(-x);
}
void upd(int x,int y,int v)
{
    for(int i=x; i<M; i+=lowbit(i))
    {
        for(int j=y; j<M; j+=lowbit(j))
        {
            a[i][j] += v;
        }
    }
}
int sum(int x,int y)
{
    int r=0;
    for(int i=x; i>0; i-=lowbit(i))
    {
        for(int j=y; j>0;j-=lowbit(j))
        {
            r+=a[i][j];
        }
    }
    return r;
}


int main()
{
    int n;
    cin>>n;
    memset(vis,0,sizeof(vis));
    memset(a,0,sizeof(a));
    while(n--)
    {
        string o;int p,q;
        cin>>o;
        if(o[0]=='Q')
        {
            int x1,x2,y1,y2;
            cin>>x1>>x2>>y1>>y2;
            x1++;x2++;y1++;y2++;
            if(x1>x2)   swap(x1,x2);
            if(y1>y2)   swap(y1,y2);
            cout<<sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1)<<endl;
        }
        else if(o[0]=='B')
        {
            cin>>p>>q;p++;q++;
            if(vis[p][q])   continue;
            upd(p,q,1);
            vis[p][q] = 1;
        }
        else
        {
            cin>>p>>q;p++;q++;
            if(!vis[p][q])   continue;
            upd(p,q,-1);
            vis[p][q] = 0;
        }

    }

    return 0;
}
