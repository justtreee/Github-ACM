#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int num[1000000];
int f(int x)
{
    while(x)
    {
        if(x%10==4||x%100==62)
            return 1;
        x/=10;
    }
    return 0;
}

int main()
{
    int n,m,ans;

    memset(num,0,sizeof(num));
    for(int i=1; i<1000000; i++)
    {
        if(f(i))
            num[i] = 1;
        //printf("%d,",num[i]);
    }
    while(scanf("%d%d",&n,&m),n&&m)
    {
        ans = 0;
        for(int i=n; i<=m; i++)
        {
            if(!num[i])
                ans++;

        }
        printf("%d\n",ans);
    }
}
