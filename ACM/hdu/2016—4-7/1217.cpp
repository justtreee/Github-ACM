//floyd+map

#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 105
#define INF (0x3f3f3f3f)
typedef long long ll;
int n,m;
double mapp[40][40];

void floyd()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n;j++)
            {
                mapp[i][j] = max(mapp[i][k]*mapp[k][j],mapp[i][j]);
            }

        }
    }
}
int main()
{
    int cas=1;
    double r;
    char c[M],c1[M],c2[M];
    while(~scanf("%d",&n)&& n)
    {

        memset(mapp,0,sizeof(mapp));
        for(int i=1; i<=n; i++)
        {
            mapp[i][i] = 1;
        }

        map<string,int> si;
        for(int i=1; i<=n; i++)
        {
            scanf("%s",c);
            si[c] = i;
        }
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            scanf("%s%lf%s",c1,&r,c2);
            mapp[si[c1]][si[c2]] = r;
        }
        floyd();
        int flag = 0;
        for(int i=1; i<=n ;i++)
        {
            if(mapp[i][i]>1)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            printf("Case %d: Yes\n",cas++);
        else
            printf("Case %d: No\n",cas++);
    }
return 0;
}
