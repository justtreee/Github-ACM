#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int f[20],t,ans;

int main()
{
    int i,k,j;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        f[0]=0;
        for(i=1;i<=8;i++)
        {
            scanf("%d",&f[i]);
            f[0]^=f[i];
        }
        scanf("%d",&f[9]);
        for(i=k=0;i<32;i++)
        {
            if(f[0]&(1<<i)) j=(k+1)%2;
            else j=k%2;
            if(f[9]&(1<<i))
            {
                if(!j) ans|=(1<<i);
            }
            else
            {
                if(j) ans|=(1<<i);
            }
            for(j=1;j<=8;j++)
            {
                if(f[j]&(1<<i))
                {
                    if(ans&(1<<i));
                    else k++;
                }
                else
                {
                    if(ans&(1<<i)) k++;
                }
            }
            k/=2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
