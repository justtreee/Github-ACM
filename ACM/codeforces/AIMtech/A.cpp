#include <bits/stdc++.h>//wa on 5
using namespace std;
int main()
{
    int n,b,d;
    scanf("%d%d%d",&n,&b,&d);
    int c=0,ans = 0;
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        if(x<b)
        {

            c+=x;
            if(c>d)
            {
                ans++;
                c=0;
            }


        }
    }
    printf("%d\n",ans);

    return 0;
}
