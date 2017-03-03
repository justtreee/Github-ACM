#include <bits/stdc++.h>
using namespace std;
int s1[100],s2[100];int i=0,j=0;
void bin(long long a,long long b)
{
    i=0,j=0;
    while(a!=0)
    {
        int t=a%2;
        s1[i++]=t;
        a/=2;
    }
    while(b!=0)
    {
        int t=b%2;
        s2[j++]=t;
        b/=2;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long a;
        long long b;
        scanf("%lld %lld",&a,&b);
        if(a==b)
        {
            printf("%lld\n",a);
        }
        else
        {
            memset(s1,0,sizeof(s1));
            memset(s2,0,sizeof(s2));
            bin(a,b);
            long long sum=0;
            int maxlen=max(i,j);
            for(int k=maxlen-1; k>=0; k--)
            {
                if(s1[k]==s2[k])
                {
                    if(s1[k]==1)
                        sum+=(long long)pow(2,k);
                }
                else
                {
                    sum+=(long long)pow(2,k+1)-1;
                    break;
                }
            }
            printf("%lld\n",sum);
        }
    }
    return 0;
}
