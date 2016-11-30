#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n,a[105],b[105];
    while(~scanf("%d",&n)&&n)
    {
        int ans =0;
        memset(b,0,sizeof(b));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(i>1)
            {
                b[i-1] = (a[i-1]-a[i]);
                cout<<b[i-1]<<" ";
            }
        }
        cout<<endl;
        //sort(b+1,b+n);
        int tmp = 0;
        for(int i=1; i<n-1; i++)
        {
            int cnt = 1;
            tmp = b[i];
            for(int j=i+1; j<n; j++)
            {
                if(b[j]*b[i]<0)
                    break;
                else
                {
                    tmp+=
                    tmp = max(tmp,abs(b[i]+b[j]));
                }
            }
            ans = max(tmp,ans);
        }
        cout<<ans<<endl;
    }

    return 0;
}
