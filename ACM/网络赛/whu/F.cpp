#include <bits/stdc++.h>
using namespace std;
const int M = 4500;
int g[M][M];
//void test(int n,int m)
//{
//    for(int i=1; i<=n+m; i++)
//    {
//        for(int j=1; j<=m+n; j++)
//        {
//            cout<<g[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//}
int main()
{
    int n,m,t;
    cin>>n>>m>>t;
    memset(g,0,sizeof(g));
    for(int i=1; i<=t; i++)
    {
        int x,y,r,x1,y1,x2,y2;
        cin>>x>>y>>r;
        x1 = x-y+m-r;   y1 = x+y-1-r;//up-left
        x2 = x-y+m+r;   y2 = x+y-1+r;//down-right
        g[x2][y2]++;
        g[x2][y1-1]--;
        g[x1-1][y2]--;
        g[x1-1][y1-1]++;
        //test();
    }
    //test(n,m);
    for(int i=1; i<=n+m; i++)
    {
        for(int j=1; j<=m+n; j++)
        {
            g[i][j] += g[i-1][j]+g[i][j-1]-g[i-1][j-1];
            //cout<<g[i][j]<<" ";
        }
        //cout<<endl;
    }
    int ans=-1,cnt = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int x = i-j+m;
            int y = i+j-1;
            if(g[x][y]>ans)
            {
                ans = g[x][y];  cnt = 1;
            }
            else if(g[x][y]==ans)
                cnt++;
        }
    }
    cout<<ans<<" "<<cnt<<endl;
    return 0;
}
