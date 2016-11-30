#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a,b,ans;
    int temp,cnt;
    while(~scanf("%d%d",&a,&b))
    {
        ans = 0;
        printf("%d %d ",a,b);
        if(a>b)
        {

            temp = a;
            a = b;
            b = temp;
        }
        for(int i=a; i<=b; i++)
        {
            int n=i;
            cnt = 1;
            while(n!=1)
            {
                if(n%2==0)
                    n/=2;
                else
                    n = n*3 +1;
                cnt++;
            }
            if(cnt>ans)
                ans = cnt;

        }
        printf("%d\n",ans);
    }
}
