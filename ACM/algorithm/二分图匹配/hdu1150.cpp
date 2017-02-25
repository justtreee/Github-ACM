#include <bits/stdc++.h>
using namespace std;
const int M=105;
int g[M][M];
int used[M],link[M];
int n,m,k;
int fnd(int u)
{
    for(int i=1; i<m; i++)
    {
        if(used[i]==0&&g[u][i])
        {
            used[i] = 1;
            if(link[i]==-1||fnd(link[i]))
            {
                link[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    while(cin>>n)
    {
        cin>>m>>k;
        if(n==0)return 0;
        int ans=0;
        memset(g,0,sizeof(g));
        memset(link,-1,sizeof(link));
        for(int i=1; i<=k; i++)
        {
            int v1,v2;
            cin>>v1>>v1>>v2;
            //if(v1&&v2)//???WA???
            g[v1][v2] = 1;
        }
        for(int i=1; i<n; i++)
        {
            memset(used,0,sizeof(used));
            if(fnd(i))
                ans++;
        }
        cout<<ans<<endl;
    }


    return 0;
}
