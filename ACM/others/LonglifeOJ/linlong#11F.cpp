#include <bits/stdc++.h>
using namespace std;
char s[1005],a[1005];
int main()
{
    int n,x[1005],y[1005];
    while(~scanf("%d",&n))
    {
        scanf("%s",a+1);
        int flag =1;
        for(int i=0 ;i<n-3; i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            if(x[i]>y[i])
                swap(x[i],y[i]);
            if(a[x[i]] == a[y[i]] )
                flag = 0;
        }
        if(flag)
        {
            for(int i=0; i<n-3; i++)
            {
                int x1 = x[i],y1 = y[i];
                for(int j=0; j<n-3; j++)
                {
                    if(i!=j)
                    {
                        int x2 = x[j],y2 = y[j];
                        if(x2>x1&&x2<y1&&y2>y1)
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
        }
        if(flag)    puts("YES");
        else        puts("NO");
    }

    return 0;
}
