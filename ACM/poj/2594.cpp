#include <bits/stdc++.h>
using namespace std;
const int M=5005;
int link[M],used[M],g[M][M];
int V1,V2;
void floyd()
{
    for(int k=1; k<=V1; k++)
    {
        for(int i=1; i<=V1; i++)
        {
            for(int j=1; j<=V2; j++)
            {
                if(!g[i][j]&&g[i][k]&&g[k][i])
                    g[i][j] = 1;
            }
        }
    }
}
bool fnd(int u)
{
    for(int i=1; i<=V2; i++)
    {
        if(used[i]==0&&g[u][i])
        {
            used[i] = 1;
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
    memset(used,0,sizeof(used));
    for(int i=1; i<=V1; i++)
    {
        if(fnd(i))
            cnt++;
    }
    return cnt;
}
int main()
{
    int n,m,a,b;
    while(scanf("%d%d",&n,&m)&&n)
    {
        memset(g,0,sizeof(g));
        memset(link,-1,sizeof(link));
        while(m--)
        {
            scanf("%d%d",&a,&b);
            g[a][b] = 1;
        }
        V1=V2=n;
        floyd();
        int cnt = match();
        //cout<<"cnt="<<cnt<<endl;
        cout<<n-cnt<<endl;
    }

    return 0;
}
