#include <cstdio>
#define  M 100005

using namespace std;
int main()
{
    int n,a[M],t;
    __int64 ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<n; i++)
        {
            scanf("%d",&a[i]);

        }
        ans = 26;
        int flag = 1;
        for(int i=1; i<n; i++)
        {
            if(a[i] == 0)
            {
                flag = 0;
            }
            if(!flag)
            {
                flag = 1;
                ans *= 25;
                ans %= 1000000007;
            }
            if(a[i-1]!=0 && a[i]!=a[i-1]-1 || a[i]>n-i)
            {
                ans = 0;
                break;
            }
        }
        printf("%I64d\n",ans%1000000007);
    }
    return 0;
}
