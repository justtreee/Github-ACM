#include <bits/stdc++.h>
using namespace std;
const int M=100;
int link[M*5],g[M*5][M*5],used[M*5];
int n,m;
bool fnd(int u)
{
    for(int i=1; i<=m; i++)
    {
        if(used[i]==0&&g[u][i])
        {
            used[i]=1;
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
        if(fnd(i))
            cnt++;
    }
    return cnt;
}
int dirx[4] = {1,-1,0,0},diry[4]={0,0,1,-1};
int main()
{
    int T,h,w,mp[M][M];
    char ch;
    scanf("%d",&T);
    while(T--)
    {
        memset(mp,0,sizeof(mp));
        memset(link,-1,sizeof(link));
        memset(g,0,sizeof(g));
        scanf("%d%d",&h,&w);getchar();
        int ip=1;
        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                scanf("%c",&ch);
                if(ch=='*')
                {
                    mp[i][j]=ip++;
                }
            }
            getchar();
        }
//        for(int i=1; i<=h; i++)
//        {
//            for(int j=1; j<=w; j++)
//            {
//                cout<<mp[i][j]<<"  ";
//            }
//            cout<<endl;
//        }
        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w;j++)
            {
                for(int k=0; k<4; k++)
                {
                    int x=i+dirx[k];
                    int y=j+diry[k];
                    if(mp[x][y])
                    {
                        g[mp[i][j]][mp[x][y]] = 1;
                    }
                }
            }
        }

        n=m=ip-1;
        cout<<n-match()/2<<endl;
    }

    return 0;
}
