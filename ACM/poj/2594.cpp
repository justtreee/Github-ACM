#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int M=600;
int link[M],used[M],g[M][M];
int n,m,a,b;
void floyd()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(!g[i][j]&&g[i][k]&&g[k][j])
                    g[i][j] =1;
            }
        }
    }
}
bool fnd(int u)
{
    for(int i=1; i<=n; i++)
    {
        if(!used[i]&&g[u][i])
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
    int res=0;
    for(int i=1; i<=n; i++)
    {
        memset(used,0,sizeof(used));
        if(fnd(i))
            res++;
    }
    return res;
}
int main()
{

    while(~scanf("%d%d",&n,&m)&&n)
    {
        memset(g,0,sizeof(g));
        while(m--)
        {
            scanf("%d%d",&a,&b);
            g[a][b] = 1;
        }
        floyd();
        memset(link,-1,sizeof(link));
        int cnt = 0;cnt = match();
        cout<<n-cnt<<endl;
    }

    return 0;
}

