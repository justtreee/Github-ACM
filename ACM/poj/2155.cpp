#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int M=1000;
int bit[M][M],a[M][M];
int T,n,m;
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int y)
{
    for(int i=x; i<=n; i+=lowbit(i))
    {
        for(int j=y; j<=n; j+=lowbit(j))
        {
            bit[i][j]++;
        }
    }
}
int sum(int x,int y)
{
    int res = 0;
    for(int i=x; i>=1; i-=lowbit(i))
    {
        for(int j=y; j>=1; j-=lowbit(j))
        {
            res+=bit[i][j];
        }
    }
    return res;
}
int main()
{

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        memset(bit,0,sizeof(bit));
        while(m--)
        {
            char op[5];
            scanf("%s",op);
            if(op[0] == 'C')
            {
                int x1,x2,y1,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                x2++,y2++;
                add(x1,y1);
                add(x1,y2);
                add(x2,y1);
                add(x2,y2);
            }
            else
            {int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",sum(x,y)%2);
            }
        }
        if(T)   printf("\n");
    }

    return 0;
}
