#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 1000
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);
int p,q;
int dx[] =  { -1, 1, -2, 2, -2, 2, -1, 1 };
int dy[] =  { -2, -2, -1, -1, 1, 1, 2, 2 };
char s[55];
int flag;
int len;
int vis[30][30];

int judge(int x,int y)
{
    return x>=0 && x<p && y>=0 && y<q;
}

void dfs(int x,int y,int cnt,char *s)
{
    if(flag)
        return;
    if(cnt==len)
    {
        //cout<<"cnt==len"<<endl;
        puts(s);
        flag = 1;
        return;

    }
    for(int i=0; i<8; i++)
    {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(judge(xx,yy) && !vis[xx][yy])
        {
            vis[xx][yy] = 1;
            s[cnt] = yy + 'A';
            s[cnt+1] = xx + '1';
            dfs(xx,yy,cnt+2,s);
            vis[xx][yy] = 0;//¿É»ØËÝ
        }
    }


}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        printf("Scenario #%d:\n",cas++);
        flag = 0;

        scanf("%d%d",&p,&q);
        len = p*q*2;
        for(int j=0; j<q; j++)
        {
            for(int i=0; i<p; i++)
            {
                memset(vis,0,sizeof(vis));
                memset(s,0,sizeof(s));
                s[0] = j+'A';
                s[1] = i+'1';
                vis[i][j] = 1;
                dfs(i,j,2,s);
                if(flag)
                    break;
            }
            if(flag)
                break;
        }

        if(!flag)
            printf("impossible\n");
        printf("\n");

    }
return 0;
}
