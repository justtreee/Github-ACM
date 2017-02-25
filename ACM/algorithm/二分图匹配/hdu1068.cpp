#include <bits/stdc++.h>
using namespace std;
const int M=500;
int g[M][M],link[M],used[M];
int n,m;
bool fnd(int u)
{
    for(int i=0; i<n; i++)
    {
        if(used[i]==0&&g[u][i])
        {
            used[i]=1;
            if(link[i]==-1||fnd(link[i]))
            {
                link[i] = u;
                return true;
            }
        }
    }
    return false;
}
int match()
{
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        memset(used,0,sizeof(used));
        if(fnd(i))
            cnt++;
    }
    return cnt;
}
int main()
{
    while(cin>>n)
    {
        memset(g,0,sizeof(g));
        int t=n;
        while(t--)
        {
            memset(link,-1,sizeof(link));
            int a,b,k;
            scanf("%d: (%d) ",&a,&k);
            while(k--)
            {
                scanf("%d",&b);
                g[a][b] = 1;
            }
        }
        cout<<n-match()/2<<endl;//建图时为双向，最大匹配要除以2
    }

    return 0;
}
