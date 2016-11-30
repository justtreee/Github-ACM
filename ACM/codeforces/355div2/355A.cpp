#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int n,h,ans,a[1005];
    while(~scanf("%d %d",&n,&h))
    {
        ans = 0;
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>h)
            {
                ans +=2;
            }
            else
            {
                ans++;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
