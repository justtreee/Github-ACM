#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;
#define M 30
#define INF (0x3f3f3f3f)
typedef long long ll;
int n,m;

int mapp[M][M],indgree[M];
int sorted[M];
int toposort(int n)
{
    int tindg[M],k=0,flag=1,mark;
    int start;
    for(int i=1; i<=n; i++)
    {
        tindg[i] = indgree[i];
    }
    for(int i=1; i<=n; i++)
    {
        mark =0;
        for(int j=1; j<=n; j++)
        {
            if(tindg[j]==0)
            {
                start = j;
                mark++;
            }
        }
        if(mark==0)
        {
            flag = 0;//huan
            break;
        }

        if(mark>=2)
            flag = -1;//wuxu
        sorted[k++] = start;
        tindg[start] = -1;
        for(int j=1; j<=n; j++)
        {
            if(mapp[start][j]==1)
                tindg[j]--;//delete start point
        }
    }
    return flag;
}
int main()
{
    char s[5];
    int fa=0;int i;
    while(~scanf("%d%d",&n,&m),n)
    {
        fa = 0;
        memset(mapp,0,sizeof(mapp));
        memset(indgree,0,sizeof(indgree));
        for(i=1; i<=m; i++)
        {
            scanf("%s",s);
            if(fa==1)
                continue;
            int x = s[0] - 'A'+1;
            int y = s[2] - 'A'+1;
            mapp[x][y] = 1;
            indgree[y]++;
            int f = toposort(n);//0==huan,1==ok,-1==wuxu
            if(f==0)
            {
                printf("Inconsistency found after %d relations.\n",i);
                fa = 1;
            }
            if(f==1)
            {
                printf("Sorted sequence determined after %d relations: ",i);
                for(int j=0;j<n;j++)
                    printf("%c",sorted[j]+'A'-1);
                printf(".\n");
                fa = 1;

            }
        }
        if(fa==0)
            printf("Sorted sequence cannot be determined.\n");
    }
return 0;
}
