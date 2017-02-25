#include <bits/stdc++.h>
using namespace std;
const int M=205;
int g[M][M],used[M],link[M];
int T,n,m;
bool fnd(int u)
{
    for(int i=1; i<=n; i++)
    {
        if(used[i]==0&&g[u][i])
        {
            used[i]=1;
            if(link[i]==-1||fnd(link[i]))
            {
                link[i]=u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin>>T;
    while(T--)
    {
        memset(g,0,sizeof(g));
        cin>>n>>m;
        for(int i=1;i<=m; i++)
        {
            int v1,v2;
            cin>>v1>>v2;
            g[v1][v2] = 1;
        }
        int cnt=0;
        memset(link,-1,sizeof(link));
        for(int i=1; i<=n; i++)
        {
            memset(used,0,sizeof(used));
            if(fnd(i))
                cnt++;
        }
        cout<<n-cnt<<endl;
    }

    return 0;
}
