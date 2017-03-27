#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
typedef long long LL;
using namespace std;
int b[33];
int cnt;
LL s=0,ans=0,n,k;
int main()
{
    scanf("%lld%lld",&n,&k);
    int i,j;
    for(i=31; i>=0; i--)
    {
        LL tmp=pow(2,i);
        if(n>=tmp)
        {
            n-=tmp;
            b[i]=1;
            cnt++;
        }
    }
    s=0;
    while(cnt>k)
    {
        for(i=s;; i++)
        {
            if(b[i])
            {
                s=i;
                b[i]=0;
                break;
            }
        }
        for(i=s+1;; i++)
        {
            if(b[i])
            {
                b[i]=0;
                cnt--;
                int x=i+1;
                while(b[x])
                {
                    b[x]=0;
                    x++;
                    cnt--;
                }
                b[x]=1;
                ans+=pow(2,i)-pow(2,s);
                s=x;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
