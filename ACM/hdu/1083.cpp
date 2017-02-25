#include <bits/stdc++.h>
using namespace std;
const int M=305;
int link[M],g[M][M],used[M];
int T,n,m,c,s;
bool fnd(int u)
{
    for(int i=1; i<=m; i++)
    {
        if(used[i]==0&&g[u][i])
        {
            used[i] =1;
            if(link[i]==-1||fnd(link[i]))
            {
                link[i] = u;    return true;
            }
        }
    }
    return false;
}
int match()
{
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        memset(used,0,sizeof(used));
        if(fnd(i))  cnt++;
    }
    return cnt;
}
int main()
{

    scanf("%d",&T);
    while(T--)
    {
        memset(g,0,sizeof(g));
        memset(link,-1,sizeof(link));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n; i++)
        {
            scanf("%d",&c);
            for(int j=1; j<=c;j++)
            {
                scanf("%d",&s);
                g[i][s] =1;
            }
        }
        if(match()==n)  cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
